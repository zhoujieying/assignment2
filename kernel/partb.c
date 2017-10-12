#include<linux/linkage.h>
#include<linux/export.h>
#include<linux/time.h>
#include<asm/uaccess.h>
#include<linux/printk.h>
#include<linux/slab.h>

asmlinkage int sys_my_xtime(struct timespec*current_time){

	if(access_ok(VERIFY_WRITE,current_time,sizeof(current_time))==0)
	{
		return EFAULT;
	}
	else
	{
		struct timespec kernel_time;
		kernel_time = current_kernel_time();
		if(copy_to_user(current_time,&kernel_time,sizeof(struct timespec))==0)
		{
			printk(KERN_ALERT"Nanosecond is:%d ",kernel_time.tv_nsec);
		}
		else
		{
			return -1;
		}
	}
	printk(KERN_ALERT"Hello World!\n");
	return 0;

}
EXPORT_SYMBOL(sys_my_xtime);
