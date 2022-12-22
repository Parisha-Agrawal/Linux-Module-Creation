#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros
#include <linux/pid.h>
#include <linux/sched.h>// task_struct
#include <linux/cred.h>

static int pid = 0;
module_param(pid, int, 0660);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("PARISHA");
MODULE_DESCRIPTION("A process detail module");

static int __init processDetails_init(void)
{
    // int pid = 853;
    // printk(KERN_INFO "new start 10:50 :)\n\n");
    printk(KERN_INFO "processDetails module loaded!\n");

	struct task_struct *task;
    task = get_pid_task(find_get_pid(pid), PIDTYPE_PID);

    pid_t pid = task->pid;
    // uid_t uid = task->uid;
    kuid_t uid = task->cred->uid;
    pid_t pgid = task->tgid;


    printk(KERN_INFO "pid :: %d\n",pid);
    printk(KERN_INFO "uid :: %d\n",uid);
    printk(KERN_INFO "pgid :: %d\n",pgid);
    printk(KERN_INFO "path :: %s\n",task->comm);


    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void __exit processDetails_cleanup(void)
{
    printk(KERN_INFO "Cleaning up module.\n");
}

module_init(processDetails_init);
module_exit(processDetails_cleanup);