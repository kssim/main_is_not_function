/*
 * Write a simple printf statement with inline asm code.
 */

void main()
{
    __asm__ (
        /* sys_write */
        "movl $1, %eax;"    // 1 is the syscall number for sys_write.
        "movl $1, %edi;"    // 1 is stdout and is the first argument for sys_write.
        "movl $msg, %esi;"  // "msg" is second argument for sys_write.
        "movl $15, %edx;"   // 15 is the length of the string in "msg". and is third argument.
        "syscall;"

        /* sys_exit */
        "movl $60, %eax;"   // 60 is the syscall number for sys_exit.
        "syscall;"

        /* variable */
        "msg: .ascii \"Hello World~!!\\n\";"
    );
}
