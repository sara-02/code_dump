//commands to run it
/*
	I don't know if that is necessary but I used these commands in the begining.
		sudo -s
		apt-get install module-assistant
		m-a prepare
	Now, in your PWD open the editor and copy the following code, making necessary changes in the logic as needed.
	lets say you save the file as <Linux_lab.c>
	now open a new file in titled Makefile 
	and copy the code from the given Makefile.Beware of intendations,each line of the file begining with default:/all:/clean: types must be followed by intended code. ALTEAST ONE TAB, else it gives error Makefile:1: *** missing separator. Stop or nothing to do in Default.
	Now open terminal and type make. This which will generate Linux_lab.ko file, it is the object file for kernel module.
	type: 
	sudo insmod Linux_lab.ko <variable name as declared in program>=<value>
	type: 
	lsmod |grep Linux_lab. This will show something as this
	Linux_lab 123444<any radom number> 0. The output of lsmod is of type <module name> <its id number> <number and names of programs currently running it.>
Now type: 
	cat /var/log/syslog
	at the end you will see your output of the progam Linux_lab.
	Now we need to unload the module 
	type: 
	sudo rmmod Linux_lab
	again check the output you will see the goodbye message this time.
	Yipee!! we learned how to load & unload a simple kernel module.	You can check again lsmod| grep Linux_lab. It will five no result as the module is no more listed.
*/


#include<linux/module.h> //loaded for listing modules

#include <linux/kernel.h> //required to get kernel INFO

#include<linux/moduleparam.h> //to pass CL parameters

#include<linux/init.h>//to allocate and free memory for loadable modules

#include<linux/stat.h>

MODULE_LICENSE("GPL");//A macro with moduleparam.h to serve as license

MODULE_AUTHOR("Sarah Masud");//another macro to store author's name

MODULE_DESCRIPTION("A loadable module to find if a number is palindrome or not");//Another macro to store short descrption of what the module does

static int number; //all values that need to passed as parameters must be declared static and global

static int sarah;//just declared but never passed as parameter, no error genreated. It means unlike C from command line, no parameter matching is done here.

module_param(number,int,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
/* the S_IRUR|... thing differs for data types, this one works for int. Why so? to set permissions*/

MODULE_PARM_DESC(number,"to store user specified value"); // you can describe what each variable mean

static int __init trying_init(void) 
/*function definition is as follows
static int __init <function name>(void)
*/
{

	int num,sum;//the local variables that use can be declare here
	sum=0;
	num=number;
	
	printk(KERN_INFO "HELLO SARAH\n*******************\n");
/*in kernel modules printk and NOT printf is used as it writes directly to the kernel file
* printk has 8 parameters KERN_INFO, KERN_LOG,KERN_WARNING, used to declare an alert message, to simpling log the value and to generate a warning 
*/
	//normal C program to find palin int :P
	while(num>0)
	{
		sum=(sum*10)+(num%10);
		num=num/10;
	}
	if(sum==number)
		printk(KERN_INFO "Number %d  IS palindrome\n============\n",number);
	else
		printk(KERN_INFO "Number %d IS NOT palindrome\n==========\n",number);
	
	return 0; //the init function must return 0, else the kernel assumes a failure and does not load the module
}

static void __exit cleanup_exit(void)
{
	printk(KERN_INFO "UNLOADING KERNEL,GOOD BYE SARAH\n*****************\n");
	//the message is displayed once module is unloaded
}

module_init(trying_init);
 /*module init function creates a space for the loadable module and the initates the modules,it logs its message in the /var/log/message file. It can be viewed using cat command. If your message file is missing then use the syslog file under /var/log, it works the same.*/

module_exit(cleanup_exit); 
/*generally modules build into the kernel use memory permanently but loadable modules should be removed after use to prevent memory loss, cleanup function basically undos whatever init fucntion did*/
