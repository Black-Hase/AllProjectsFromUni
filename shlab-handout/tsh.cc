// 
// tsh - A tiny shell program with job control
// 
// <Put your name and login ID here>
//

using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <string>
//include <iostream> so that it allows endl
#include <iostream>

#include "globals.h"
#include "jobs.h"
#include "helper-routines.h"

//
// Needed global variable definitions
//

static char prompt[] = "tsh> ";
int verbose = 0;

//
// You need to implement the functions eval, builtin_cmd, do_bgfg,
// waitfg, sigchld_handler, sigstp_handler, sigint_handler
//
// The code below provides the "prototypes" for those functions
// so that earlier code can refer to them. You need to fill in the
// function bodies below.
// 

void eval(char *cmdline);
int builtin_cmd(char **argv);
void do_bgfg(char **argv);
void waitfg(pid_t pid);

void sigchld_handler(int sig);
void sigtstp_handler(int sig);
void sigint_handler(int sig);

//
// main - The shell's main routine 
//
int main(int argc, char **argv) 
{
  int emit_prompt = 1; // emit prompt (default)

  //
  // Redirect stderr to stdout (so that driver will get all output
  // on the pipe connected to stdout)
  //
  dup2(1, 2);

  /* Parse the command line */
  char c;
  while ((c = getopt(argc, argv, "hvp")) != EOF) {
    switch (c) {
    case 'h':             // print help message
      usage();
      break;
    case 'v':             // emit additional diagnostic info
      verbose = 1;
      break;
    case 'p':             // don't print a prompt
      emit_prompt = 0;  // handy for automatic testing
      break;
    default:
      usage();
    }
  }

  //
  // Install the signal handlers
  //

  //
  // These are the ones you will need to implement
  //
  Signal(SIGINT,  sigint_handler);   // ctrl-c
  Signal(SIGTSTP, sigtstp_handler);  // ctrl-z
  Signal(SIGCHLD, sigchld_handler);  // Terminated or stopped child

  //
  // This one provides a clean way to kill the shell
  //
  Signal(SIGQUIT, sigquit_handler); 

  //
  // Initialize the job list
  //
  initjobs(jobs);

  //
  // Execute the shell's read/eval loop
  //
  for(;;) {
    //
    // Read command line
    //
    if (emit_prompt) {
      printf("%s", prompt);
      fflush(stdout);
    }

    char cmdline[MAXLINE];

    if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin)) {
      app_error("fgets error");
    }
    //
    // End of file? (did user type ctrl-d?)
    //
    if (feof(stdin)) {
      fflush(stdout);
      exit(0);
    }

    //
    // Evaluate command line
    //
    eval(cmdline);
    fflush(stdout);
    fflush(stdout);
  } 

  exit(0); //control never reaches here
}
  
/////////////////////////////////////////////////////////////////////////////
//
// eval - Evaluate the command line that the user has just typed in
// 
// If the user has requested a built-in command (quit, jobs, bg or fg)
// then execute it immediately. Otherwise, fork a child process and
// run the job in the context of the child. If the job is running in
// the foreground, wait for it to terminate and then return.  Note:
// each child process must have a unique process group ID so that our
// background children don't receive SIGINT (SIGTSTP) from the kernel
// when we type ctrl-c (ctrl-z) at the keyboard.
//
void eval(char *cmdline) 
{
  /* Parse command line */
  //
  // The 'argv' vector is filled in by the parseline
  // routine below. It provides the arguments needed
  // for the execve() routine, which you'll need to
  // use below to launch a process.
  //
  int pid;
  char *argv[MAXARGS];
  sigset_t mask;

  //
  // The 'bg' variable is TRUE if the job should run
  // in background mode or FALSE if it should run in FG
  //
  int bg = parseline(cmdline, argv); 
  struct job_t *job;
    if(!builtin_cmd(argv))
    {
        sigemptyset(&mask);
        sigaddset(&mask, SIGCLD);
        sigprocmask(SIG_BLOCK, &mask, NULL);
        //fork & exec the specified program
        
        if ((pid=fork())==0)
        {
            //in child
            sigprocmask(SIG_UNBLOCK, &mask, NULL);
            setpgid(0,0);
            if(execvp(argv[0], argv) < 0){
                printf("%s: Command not found\n", argv[0]);
                exit(1);
            }
        }
        else
        {
            if(!bg) 
        {
            ///handle reaping 
            addjob(jobs, pid, FG, cmdline);
        }
              else{
                    addjob(jobs, pid, BG, cmdline);   
        }
        }
        sigprocmask(SIG_UNBLOCK, &mask, NULL);
        
        if(!bg)
        {
            waitfg(pid); // sleep comand
        }
        else {
            printf("[%d] (%d) %s", pid2jid(pid), pid, cmdline);
        }
    }
  if (argv[0] == NULL)  
    return;   /* ignore empty lines */

  return;
}


/////////////////////////////////////////////////////////////////////////////
//
// builtin_cmd - If the user has typed a built-in command then execute
// it immediately. The command name would be in argv[0] and
// is a C string. We've cast this to a C++ string type to simplify
// string comparisons; however, the do_bgfg routine will need 
// to use the argv array as well to look for a job number.
//
int builtin_cmd(char **argv) 
{
    //handles the overal builtin camands calls the required funtions if need or exits if the quit is sent. these compare the argumetn lines with the second arguments pasted into the strcomp function. you could also do it with an just the campare don head and if that mached the "quated" section.
  
    if(strcmp(argv[0],"quit")==0)
  {
      exit(0);
  }
    if(((strcmp(argv[0],"fg"))/*||(strcmp(argv[0],"bg"))*/)==0)
  {
        //handle the fg command
        do_bgfg(argv);
      return 1;
  }
   if(strcmp(argv[0],"bg")==0)
  {
      //handle the bg command
      do_bgfg(argv);
        return 1;
        
  }
   if(strcmp(argv[0],"jobs")==0)
  {
      //handle the jobs command
      listjobs(jobs); // list the jobs
        return 1;
  }
   if(strcmp(argv[0], "&")==0)
    {
        return 1; // if this returns one the use of the built in camand function will push things to the background
    }
string cmd(argv[0]);
  return 0;     /* not a builtin command */
}

/////////////////////////////////////////////////////////////////////////////
//
// do_bgfg - Execute the builtin bg and fg commands
//
void do_bgfg(char **argv) 
{
  struct job_t *jobp=NULL;
    
  /* Ignore command if no argument */
  if (argv[1] == NULL) {
    printf("%s command requires PID or %%jobid argument\n", argv[0]);
    return;
  }
    
  /* Parse the required PID or %JID arg */
  if (isdigit(argv[1][0])) {
    pid_t pid = atoi(argv[1]);
    if (!(jobp = getjobpid(jobs, pid))) {
      printf("(%d): No such process\n", pid);
      return;
    }
  }
  else if (argv[1][0] == '%') {
    int jid = atoi(&argv[1][1]);
    if (!(jobp = getjobjid(jobs, jid))) {
      printf("%s: No such job\n", argv[1]);
      return;
    }
  }	    
  else {
    printf("%s: argument must be a PID or %%jobid\n", argv[0]);
    return;
  }

  //
  // You need to complete rest. At this point,
  // the variable 'jobp' is the job pointer
  // for the job ID specified as an argument.
  //
  // Your actions will depend on the specified command
  // so we've converted argv[0] to a string (cmd) for
  // your benefit.
  //
  string cmd(argv[0]);
    kill(-jobp->pid,SIGCONT); 
    if(cmd == "fg")// camand is comparted to fg if true then the job's pointer state is set to forground and is passed to the waitfg which could cause a sleep
    {
        jobp->state = FG;
        waitfg(jobp->pid);
    }
    else
    {
        //otherwise the job must be a background and the print is shown to user
        printf("[%d] (%d) %s", jobp->jid, jobp->pid, jobp->cmdline);
        jobp->state=BG;
    }

  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// waitfg - Block until process pid is no longer the foreground process
//
void waitfg(pid_t pid)
{
    struct job_t *job =getjobpid(jobs, pid); // job pointer is set tot he result of the getjobpid function which with get the pid of the job
    if(pid==0) //if the pid is zero do nothing
    {
        return;
    }
    while (job->state == FG) // while the job is in the forground sleep. 1 sec is only needed because the sleep will keep repeating n times
    {
        sleep(1);
    }
    /*
    if(job !=NULL)
    {
    while(pid==fgpid(jobs)){} THIS MIGHT BE BETTER????
    }
    */
  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// Signal handlers
//


/////////////////////////////////////////////////////////////////////////////
//
// sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
//     a child job terminates (becomes a zombie), or stops because it
//     received a SIGSTOP or SIGTSTP signal. The handler reaps all
//     available zombie children, but doesn't wait for any other
//     currently running children to terminate.  
//
void sigchld_handler(int sig) 
{
    int pid;
    int status;

    /*while((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        //job = getjobpid(jobs, pid);
        deletejob(jobs,pid);
    }*/
    while((pid = waitpid(fgpid(jobs), &status, WNOHANG|WUNTRACED)/*basically if the child is stoped or terminated carry out these next steps*/) > 0)
        if(WIFSTOPPED(status))
        {
            getjobpid(jobs, pid)->state = ST; // if the child was stoped than we set its state to stopped
            int jid = pid2jid(pid); // gets the job id based on the pid so we can print it out
        printf("Job [%d] (%d) Stopped by signal %d \n", jid, pid, WSTOPSIG(status)); 
        }
        else if (WIFSIGNALED(status)) //if the child terminated because of a signal that was not caught WIFSIGNALED returns true /// basically if things exited unexpected or unusualy
               {
                   //printf("Hello\n");
                   int jid = pid2jid(pid);
                   printf("Job [%d] (%d) terminated by signal %d \n", jid, pid, WTERMSIG(status)); // WTERMSIG REturns the number of the signal that causeed the child process to terminate This status is only defined if WIFSIGNALED() returned true.
                       deletejob(jobs, pid); // delets the job from the job list. which might be artifical construct that we create to keep track of what is being done.
               }
        else if (WIFEXITED(status)) //WIFEXCITED returns true if the child terminated normally, via a call to exit or a return. ///// if the exit happened normally we dont need to know why
               {
                   deletejob(jobs, pid);
               }

      
 
  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// sigint_handler - The kernel sends a SIGINT to the shell whenver the
//    user types ctrl-c at the keyboard.  Catch it and send it along
//    to the foreground job.  
//
void sigint_handler(int sig) //similur to sigtstp_handler
{
  int pid = fgpid(jobs);
  //std::cout <<"called sigtint_handler/\n" << std::endl <<
  //  std::flush;
  if (pid>0) //if the id is not 0 
  {
      int success = kill(-pid,SIGINT); //then interupt the process
         if(success<0) // if its negative
    {
        unix_error("kill (tstp) error"); 
    }
      
  }
 
  return;
}

/////////////////////////////////////////////////////////////////////////////
//
// sigtstp_handler - The kernel sends a SIGTSTP to the shell whenever
//     the user types ctrl-z at the keyboard. Catch it and suspend the
//     foreground job by sending it a SIGTSTP.  
//
void sigtstp_handler(int sig) 
{
    
    int pid = fgpid(jobs); // found in jobs
// std::cout <<"called sigtstp_handler/\n" << std::endl <<
  //  std::flush; // this is just to see whats happening
    
    if(pid > 0)
    {
        //do something return 0 if success 1 if it isnt
        int success = kill(-pid, SIGTSTP/* tell it which signal*/); // for every child you creat useing fork methode you want to make sure its in its own seperate group to be able to kill it its extreamlly important to do this. 
        if(success<0)
        {
            //error printed
            unix_error("kill (tstp) error");
        }
      // we dont wnat this here because if we go to ./tshref then /bin/sleep 1000 because we could put it here or we could put it in the sigchild handler  std::cout << "sigstp_handler:job ["<<pid2jid(pid)"] ("<<pid <<") stopped" << std::endl; //tsatref does this so we want to print it basically
        
    }
    return;
}

/*********************
 * End signal handlers
 *********************/




