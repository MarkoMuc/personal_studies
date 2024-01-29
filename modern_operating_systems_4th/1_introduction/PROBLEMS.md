# Chapter 1: Problems

1. What are the two main functions of an operating system?

- Reasource management and resource abstraction.

2. What is multiprogramming?

- Multiprogramming is a technique used for minimizing resource idle time, specifically the CPU idle time. This is normally achieved by keeping more than one program in the memory at the same time. When one of the processers stops(e.g. waiting on I/O operations), the CPU is allocated to one of the other processes in the memory. Thus the CPU is kept busy at all times.

3. In Sec. 1.4, nine different types of operating systems are described. Give a list of possible applications for each of these systems (at least one for each of the operating systems types).

- Mainframe OS: HPC, large data handling and processing.
- Server OS: Websites, webapps, web based mobile apps, multiplayer games, etc.
- Personal Computer OS: Personal use, office work, etc.
- Smartphone and Handheld computer OS: Smartphones, tablets.
- IoT and Embedded OS: Home assistant, car computers, watches, industry machine control, security.
- Real-Time OS: Airplanes, cars, heavy machinery, industry data collection and monitoring.
- Smart Card OS: smartcards.

4. To use cache memory, main memory is divided into cache lines, typically 32 or 64 bytes long. An entire cache line is cached at once. What is the advantage of caching an entire line instead of a single byte or word at a time?

- The main reason is locality of reference, this is the tendency of a CPU to access the same set of memory locations repetitively over a short period of time. Thus leading to less cache misses. Reading data in chunks is also faster than word by word.

5. What is spooling? Do you think that advanced personal computers will have spooling as a standard feature in the future?

- Spooling is the ability of reading jobs from cards onto the disk as soon as they were brought into the room. Whenever a running job finished, the OS could load a new job form the disk into the new-empty partition and running it. Today cards for storing are not used anymore, thus spooling at its pure form is not needed anymore.

6. On early computers, every byte of data read or written was handled by the CPU (i.e., there was no DMA). What implications does this have for multiprogramming?

- This means multiprogramming was practically impossible, since the CPU was busy at almost all times. The main advantage of multiprogramming is maximising the CPU usage, this can be done, when a process does not need to use the CPU, thus CPU time can be allocated to other jobs. If the CPU is used for data transfer, CPU switching during I/O operations is not possible, since the CPU needs to pass the data directly to the I/O.

7. Why was timesharing not widespread on second-generation computers?

- The hardware just not capable of taking full advantage of timesharing.

8. Instructions related to accessing I/O devices are typically privileged instructions, that is, they can be executed in kernel mode but not in user mode. Give a reason why these instructions are privileged.

- This prevents processes from interfering with other processes, while they are performing I/O. An example is a process for chainging the password. It also enforces user restrictions.

9. One reason GUIs were initially slow to be adopted was the cost of the hardware needed to support them. How much video RAM is needed to support a 25-line × 80-row
character monochrome text screen? How much for a 1024 × 768-pixel 24-bit color bit- map? What was the cost of this RAM at 1980 prices ($5/KB)? How much is it now?

- 25 * 80 * 1 byte = 2 000byte memory => $10
- 1024 * 768 * 24 = 18874368 bit memory => $11.796,48

10. There are several design goals in building an operating system, for example, resource utilization, timeliness, robustness, and so on. Give an example of two design goals that may contradict one another.

- Resurce utilization and security. Resource management and utilization is controlled by the kernel in kernel mode, as such this operations are much more expensive. At the same time this brings better security to OS, not allowing malicous operations. Also fairness and real time.

11. What is the difference between kernel and user mode? Explain how having two distinct modes aids in designing an operating system.

- Kernel mode is a priviliged mode, where all operations are permitted aswell as usage of all hardware functionalities. Kernel mode is accessible by trapping the system, often access to the kernel mode is also supported by the hardware, specifically the CPU. User mode is the less priviliged mode, that has to ask the kernel to perform specific operations in its place. Since there is no need to trap the CPU, user mode calls are much faster. Having two distinct modes allows for separation of the problems, issues in one segment can are more isolated and fixing them does not lead to changing the other part. Also denying access to critical instructions.

12. A 255-GB disk has 65,536 cylinders with 255 sectors per track and 512 bytes per sector. How many platters and heads does this disk have? Assuming an average cylinder seek time of 11 msec, average rotational delay of 7 msec. and reading rate of 100 MB/sec, calculate the average time it will take to read 100 KB from one sector.

- Heads =  255 GB / (65536*255*512) = 16.
- Number of platters = 16/2 = 8.
- Seek time + rotational latency + transfer time = 11ms + 7ms + 4ms = 22msec.

13. Consider a system that has two CPUs, each CPU having two threads (hyperthreading). Suppose three programs, P0, P1, and P2, are started with run times of 5, 10 and 20 msec, respectively. How long will it take to complete the execution of these programs? Assume that all three programs are 100% CPU bound, do not block during execution, and do not change CPUs once assigned.

- 20, 25, 30 or 35 msec.

14. List some differences between personal computer operating systems and mainframe operating systems.

- Mainframe OSs are less interactive, their goal is large processing and I/O throughput as opposed to personal computer OSs, which goal is fast response times to user interactions.

15. A computer has a pipeline with four stages. Each stage takes the same time to do its work, namely, 1 nsec. How many instructions per second can this machine execute?

- After 4 nsec the first instruction is performed, afterwards every nsec an instruction finishes. Meaning 1e9 - 3 instructions. 

16. Consider a computer system that has cache memory, main memory (RAM) and disk, and an operating system that uses virtual memory. It takes 2 nsec to access a word from the cache, 10 nsec to access a word from the RAM, and 10 msec to access a word from the disk. If the cache hit rate is 95% and main memory hit rate (after a cache miss) is 99%, what is the average time to access a word?

- 0.95 * 2nsec + 0.05 * 0.99 * 10nsec + 0.05 * 0.01 * 10msec = 5.0014445 micro seconds.

17. When a user program makes a system call to read or write a disk file, it provides an indication of which file it wants, a pointer to the data buffer, and the count. Control is then transferred to the operating system, which calls the appropriate driver. Suppose that the driver starts the disk and terminates until an interrupt occurs. In the case of reading from the disk, obviously the caller will have to be blocked (because there are no data for it). What about the case of writing to the disk? Need the caller be blocked awaiting completion of the disk transfer?

- Maybe, if the caller changes the data that should be written, then wrong data will be written to the disk. If the data is cached beforehand, then there is no problem.

18. What is the key difference between a trap and an interrupt?

- Traps switch the CPU mode, interrupts are handled by the OS.

19. Is there any reason why you might want to mount a file system on a nonempty directory? If so, what is it?

- As a backup for important files, since whats inside the mount point becomes inaccessible after mounting.

20. What is the purpose of a system call in an operating system?

- To perform kernel mode procedures.

21. Give one reason why mounting file systems is a better design option than prefixing path names with a drive name or number. Explain why file systems are almost always mounted on empty directories.

- Prefixing path names creates device dependency. File systems are mounted on empty directories, so all data is accessible.

22. For each of the following system calls, give a condition that causes it to fail: open, close, and lseek.

- open fails if the file descriptor is not valid, same for close and lseek.
- lseek fails if offset points past the end of the file.

23. What type of multiplexing (time, space, or both) can be used for sharing the following resources: CPU, memory, SSD/disk, network card, printer, keyboard, and display?

- Time: CPU, network card, printer, keyboard.
- Space: memory, disk.
- Both: display.

24. Can the `count = write(fd, buffer, nbytes);` call return any value in count other than nbytes? If so, why?

- The return value can be -1 if an error occurs(such as file descriptor being invalid). Otherwise it can be less because there is not enough space on the disk, it is interrupted, etc.

25. A file whose file descriptor is fd contains the following sequence of bytes: `2, 7, 1, 8, 2, 8, 1, 8, 2, 8, 4`. The following system calls are made: 
`lseek(fd, 3, SEEK SET); 
read(fd, &buffer, 4);` 
where the lseek call makes a seek to byte 3 of the file. What does buffer contain after the read has completed?

- It contains: 8,2,8,1.

26. Suppose that a 10-MB file is stored on a disk on the same track (track 50) in consecutive sectors. The disk arm is currently situated over track number 100. How long will it take to retrieve this file from the disk? Assume that it takes about 1 msec to move the arm from one cylinder to the next and about 5 msec for the sector where the beginning of the file is stored to rotate under the head. Also, assume that reading occurs at a rate of 100 MB/s.

- Time to retrieve the file: 1 * 50 ms (Time to move the arm over track 50) + 5 ms (Time for the first sector to rotate under the head) 10/200 * 1000 ms (Read 10 MB) = 105 ms

27. What is the essential difference between a block special file and a character special file?

- Block special files consist of numbered blocks, each of which can be read or written independently of all the other ones. It is possible to seek any block and start reading or writing. This is not possible with a character special file.

28. In the example given in Fig. 1-17, the library procedure is called read and the system call itself is called read. Is it essential that both of these have the same name? If not, which one is more important? 

- The name of the system call is not important, since system calls are called by their index and a CPU trap. Names are more important in library procedure calls, since it makes code more readable.

29. The client-server model is popular in distributed systems. Can it also be used in a single-computer system?

- It can be used in a single-computer system, it would even lead to a faster message exchange, since the network overhead is not present.

30. To a programmer, a system call looks like any other call to a library procedure. Is it important that a programmer know which library procedures result in system calls? Under what circumstances and why?

- It is important if performance is an issue, since system calls bring kernel mode overhead. In multiprogramming systems, the CPU may even schedule another process leading to more overhead and slower real-time performance.

31. Figure 1-23 shows that a number of UNIX system calls have no Win32 API equivalents. For each of the calls listed as having no Win32 equivalent, what are the consequences for a programmer of converting a UNIX program to run under Windows?

- Link: a Win32 program cannot refer to a file by an alternative name or see it in another directory. Also creating a link is a convenient way to test for amd create a lock on a file.
- Mount and unmount: a Win32 program cannot make assumptions about standard path names because on systems with multiple disk drives the drive-name paths of the path may be different.
- Chmod: Windows uses access control lists.
- Kill: Windows programs cannot kill misbehaving programs.

32. A portable operating system is one that can be ported from one system architecture to another without any modification. Explain why it is infeasible to build an operating system that is completely portable. Describe two high-level layers that you will have in designing an operating system that is highly portable. 

- A portable OS in infeasible because of hardware differences, CPU architectures, bus architectures, CPU instruction sets, etc. 
- A highly portable OS would consist of two layers, a machine-dependent and a machine-independent layer. The former must be implemented seperately for every architecture, while the latter has to be built only once and is built upon the machine-dependent one. To make it portable, the machine-dependent layer needs to kept as small as possible.

33. Explain how separation of policy and mechanism aids in building microkernel-based operating systems.

- It allows implementation of small number of basic primitives in the kernel. These primitives are simplified, because they are indepentent of any policy. They can be used to implement more complex mechanisms and policies at the user level. 

34. Virtual machines have become very popular for a variety of reasons. Nevertheless, they have some downsides. Name one.

- Increased memory usage and processor overhead as well as increased performance overhead.

35. Here are some questions for practicing unit conversions:
- (a) How long is a microyear in seconds? 31.536s.
- (b) Micrometers are often called microns. How long is a gigamicron? 1km.
- (c) How many bytes are there in a 1-TB memory? 1e+12
- (d) The mass of the earth is 6000 yottagrams. What is that in grams? 6 × e27 g.

36. Write a shell that is similar to Fig. 1-19 but contains enough code that it actually works so you can test it. You might also add some features such as redirection of input and output, pipes, and background jobs.

- Implementation is in `implementations/shell.c` and can be compiled with `gcc shell.c`.
- It can also run background processes.

37. If you have a personal UNIX-like system (Linux, MINIX 3, FreeBSD, etc.) available that you can safely crash and reboot, write a shell script that attempts to create an unlimited number of child processes and observe what happens. Before running the experiment, type sync to the shell to flush the file system buffers to disk to avoid ruin- ing the file system. You can also do the experiment safely in a virtual machine. Note: Do not try this on a shared system without first getting permission from the system administrator. The consequences will be instantly obvious so you are likely to be caught and sanctions may follow.

- In most Linux systems, fork bombs(creating a large ammount of child processes) is not possible anymore(by default). As such this did not crash the system, the OS started closing down the spawned processes.
- Implementation is in `implementations/crash.sh`.

38. Examine and try to interpret the contents of a UNIX-like or Windows directory with a tool like the UNIX od program. (Hint: How you do this will depend upon what the OS allows. One trick that may work is to create a directory on a USB stick with one operating system and then read the raw device data using a different operating system that allows such access.)

