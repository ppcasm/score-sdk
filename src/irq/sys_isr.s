// General Registers Symbolic
#define    SP        r0
#define    AT        r1
#define    BP        r2
#define    LR        r3
#define    A0        r4
#define    A1        r5
#define    A2        r6
#define    A3        r7
#define    T0        r8
#define    T1        r9
#define    T2        r10
#define    T3        r11
#define    S0        r12
#define    S1        r13
#define    S2        r14
#define    S3        r15
#define    S4        r16
#define    S5        r17
#define    S6        r18
#define    S7        r19
#define    S8        r20
#define    S9        r21
#define    T4        r22
#define    T5        r23
#define    T6        r24
#define    T7        r25
#define    T8        r26
#define    T9        r27
#define    R28       r28
#define    JP        r29
#define    K0        r30
#define    K1        r31

// CP0 Registers
#define CP0_STATUS   cr0
#define CP0_COND     cr1
#define CP0_CAUSE    cr2
#define CP0_EXCPVEC  cr3
#define CP0_CCR      cr4
#define CP0_EPC      cr5
#define CP0_BADVA    cr6
#define CP0_WIRE     cr7
#define CP0_INDEX    cr8
#define CP0_CONTEXT  cr9
#define CP0_RANDOM   cr10
#define CP0_ENTRYHI  cr11
#define CP0_ENTRYLO  cr12
#define CP0_FMARLO   cr13
#define CP0_FMARHI   cr14
#define CP0_FMCR     cr15
#define CP0_FFMR     cr16
#define CP0_LLADDR   cr17
#define CP0_PREV     cr18
#define CP0_DREG     cr29
#define CP0_DEPC     cr30
#define CP0_DSAVE    cr31
#define SPR_HI	     sr1    		
#define SPR_LO	     sr2 

#define STACK_SIZE   32

.org 0
.section .exception_vec,"ax"
//=========================================================
// General/Debug
//=========================================================
.align 2
norm_debug_vec:         // DebugVec
    j norm_debug_service

.align 2
general_vec:            // GeneralVec
    j general_service
    
//=========================================================
// IRQ 1~63
//=========================================================
.align 2
.global int1_vec // Make this one global so we can reference the start of vector addr
int1_vec:               // IRQ1
    j int_service       // int_service
.align 2
int2_vec:               // IRQ2
    j int_service       // int_service
.align 2
int3_vec:               // IRQ3
    j int_service       // int_service
.align 2
int4_vec:               // IRQ4
    j int_service       // int_service
.align 2
int5_vec:               // IRQ5
    j int_service       // int_service
.align 2
int6_vec:               // IRQ6
    j int_service       // int_service
.align 2
int7_vec:               // IRQ7
    j int_service       // int_service
.align 2
int8_vec:               // IRQ8
    j int_service       // int_service
.align 2
int9_vec:               // IRQ9
    j int_service       // int_service
.align 2
int10_vec:              // IRQ10
    j int_service       // int_service
.align 2
int11_vec:              // IRQ11
    j int_service       // int_service
.align 2
int12_vec:              // IRQ12
    j int_service       // int_service
.align 2
int13_vec:              // IRQ13
    j int_service       // int_service
.align 2
int14_vec:              // IRQ14
    j int_service       // int_service
.align 2
int15_vec:              // IRQ15
    j int_service       // int_service
.align 2
int16_vec:              // IRQ16
    j int_service       // int_service
.align 2
int17_vec:              // IRQ17
    j int_service       // int_service
.align 2
int18_vec:              // IRQ18
    j int_service       // int_service
.align 2
int19_vec:              // IRQ19
    j int_service       // int_service
.align 2
int20_vec:              // IRQ20
    j int_service       // int_service
.align 2
int21_vec:              // IRQ21
    j int_service       // int_service
.align 2
int22_vec:              // IRQ22
    j int_service       // int_service
.align 2
int23_vec:              // IRQ23
    j int_service       // int_service
.align 2
int24_vec:              // IRQ24
    j save_reg          // save_reg
.align 2
int25_vec:              // IRQ25
    j save_reg          // save_reg
.align 2
int26_vec:              // IRQ26
    j save_reg          // save_reg
.align 2
int27_vec:              // IRQ27
    j save_reg          // save_reg
.align 2
int28_vec:              // IRQ28
    j save_reg          // save_reg
.align 2
int29_vec:              // IRQ29
    j save_reg          // save_reg
.align 2
int30_vec:              // IRQ30
    j save_reg          // save_reg
.align 2
int31_vec:              // IRQ31
    j save_reg          // save_reg
.align 2
int32_vec:              // IRQ32
    j save_reg          // save_reg
.align 2
int33_vec:              // IRQ33
    j save_reg          // save_reg
.align 2
int34_vec:              // IRQ34
    j save_reg          // save_reg
.align 2
int35_vec:              // IRQ35
    j save_reg          // save_reg
.align 2
int36_vec:              // IRQ36
    j save_reg          // save_reg
.align 2
int37_vec:              // IRQ37
    j save_reg          // save_reg
.align 2
int38_vec:              // IRQ38
    j save_reg          // save_reg
.align 2
int39_vec:              // IRQ39
    j save_reg          // save_reg
.align 2
int40_vec:              // IRQ40
    j save_reg          // save_reg
.align 2
int41_vec:              // IRQ41
    j save_reg          // save_reg
.align 2
int42_vec:              // IRQ42
    j save_reg          // save_reg
.align 2
int43_vec:              // IRQ43
    j save_reg          // save_reg
.align 2
int44_vec:              // IRQ44
    j save_reg          // save_reg
.align 2
int45_vec:              // IRQ45
    j save_reg          // save_reg
.align 2
int46_vec:              // IRQ46
    j save_reg          // save_reg
.align 2
int47_vec:              // IRQ47
    j save_reg          // save_reg
.align 2
int48_vec:              // IRQ48
    j save_reg          // save_reg
.align 2
int49_vec:              // IRQ49
    j save_reg          // save_reg
.align 2
int50_vec:              // IRQ50
    j save_reg          // save_reg
.align 2
int51_vec:              // IRQ51
    j save_reg          // save_reg
.align 2
int52_vec:              // IRQ52
    j save_reg          // save_reg
.align 2
int53_vec:              // IRQ53
    j save_reg          // save_reg
.align 2
int54_vec:              // IRQ54
    j save_reg          // save_reg
.align 2
int55_vec:              // IRQ55
    j save_reg          // save_reg
.align 2
int56_vec:              // IRQ56
    j save_reg          // save_reg
.align 2
int57_vec:              // IRQ57
    j save_reg          // save_reg
.align 2
int58_vec:              // IRQ58
    j save_reg          // save_reg
.align 2
int59_vec:              // IRQ59
    j save_reg          // save_reg
.align 2
int60_vec:              // IRQ60
    j save_reg          // save_reg
.align 2
int61_vec:              // IRQ61
    j save_reg          // save_reg
.align 2
int62_vec:              // IRQ62
    j save_reg          // save_reg
.align 2
int63_vec:              // IRQ63
    j save_reg          // save_reg

//=========================================================
// MGA BratzLife hack
// This should be fine to compile with all other systems
//
// The BratzLife loader has a critical flaw in that it copies
// the payload from SD card from address 0xA00001FC to past
// entry address of 0xA0001000. The problem with this is that
// the loader they're doing the copy from is stored at
// 0xA0000310. I was going to make it a linkerscript hack but
// decided that it's probably easiest to just add it here since
// it will live in the intvec handling area anyway and will just
// be cooked into all binaries since the area is used anyway and
// would otherwise be filled with 0x00 values. 
//
// This hack works by simply replicating the loader bytes at the fixed
// address so that when it does go to self modify, it is just copying the
// same bytes at the same location so the load can finish properly.

// My guess is that they didn't notice this was even happening because they
// likely kept uploading the same code with that loader at that same
// fixed address.
//
//
//=========================================================
bratzlife_fix:
.byte 0x30, 0x52, 0x15, 0x00, 0xb0, 0x89, 0x4f, 0x01, 0x84, 0x5d, 0x06, 0xa5, 0x14, 0x5d, 0x75, 0x11 
.byte 0x00, 0x80, 0x18, 0x85, 0x00, 0x80, 0x00, 0x99, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x1a, 0x95, 0xf8, 0x83, 0x14, 0x85, 0x10, 0x94, 0x28, 0x81
.byte 0x0b, 0x80, 0x44, 0x9d, 0x0f, 0x80, 0x48, 0x9d, 0x93, 0x28, 0xfb, 0x47, 0x00, 0x00, 0x00, 0x00
.byte 0x00, 0x80, 0x00, 0x80, 0x00, 0xc0, 0x5a, 0x95, 0x00, 0xa0, 0x54, 0x85, 0x08, 0xbc, 0x0a, 0x80

.extern intmsg          // intmsg from sys_irq.c
//=========================================================
// IRQ SVC
//=========================================================
norm_debug_service:     // Debug
    jl intmsg           // intmsg();

general_service:        // General
    jl intmsg           // intmsg();

int_service:
    jl intmsg           // intmsg();

//=========================================================
// void intmsg(void)
// General exception/svc/debug - unimplemented for now
//
//
//=========================================================
intmsg:
	j intmsg
	nop
	
.extern irq_dispatch    // irq_dispatch from sys_irq.c
.set r1

//=========================================================
// void save_reg(void)
// Save all registers and jump to interrupt label table
// After completing service routine, then restore all 
// registers
//
//=========================================================
save_reg:
	// Save registers
    subi SP, 0x98
    sw r1,  [SP, 0x4]
    sw r2,  [SP, 0x8]
    sw r3,  [SP, 0xC]
    sw r4,  [SP, 0x10]
    sw r5,  [SP, 0x14]
    sw r6,  [SP, 0x18]
    sw r7,  [SP, 0x1C]
    sw r8,  [SP, 0x20]
    sw r9,  [SP, 0x24]
    sw r10, [SP, 0x28]
    sw r11, [SP, 0x2C]
    sw r12, [SP, 0x30]
    sw r13, [SP, 0x34]
    sw r14, [SP, 0x38]
    sw r15, [SP, 0x3C]
    sw r16, [SP, 0x40]
    sw r17, [SP, 0x44]
    sw r18, [SP, 0x48]
    sw r19, [SP, 0x4C]
    sw r20, [SP, 0x50]
    sw r21, [SP, 0x54]
    sw r22, [SP, 0x58]
    sw r23, [SP, 0x5C]
    sw r24, [SP, 0x60]
    sw r25, [SP, 0x64]
    sw r26, [SP, 0x68]
    sw r27, [SP, 0x6C]
    sw r28, [SP, 0x70]
    sw r29, [SP, 0x74]
    sw r30, [SP, 0x78]
    sw r31, [SP, 0x7C]
    mfcr    r13, cr1
    nop
    nop
    nop
    nop
    nop
    mfcr    r15, cr5
    nop
    nop
    nop
    nop
    nop
    sw r13, [SP, 0x84]
    sw r15, [SP, 0x8C]
	mfcehl r13, r14
	nop
	nop
	nop
	nop
	nop
	sw r13, [SP, 0x90]
	sw r14, [SP, 0x94]
    mfcr    r4, cr2
    nop
    nop
    nop
    nop
    nop
    jl	irq_dispatch
    nop
    
    // Restore registers
    lw r13, [SP, 0x90]
    lw r14, [SP, 0x94]
    mtcehl r13, r14
    nop
    nop
    nop
    nop
    nop
    lw r30, [SP, 0x84]
    lw r31, [SP, 0x8C]
    mtcr r30, cr1
    nop
    nop
    nop
    nop
    nop
    mtcr r31, cr5
    nop
    nop
    nop
    nop
    nop
    lw r1,  [SP, 0x04]
    lw r2,  [SP, 0x08]
    lw r3,  [SP, 0x0C]
    lw r4,  [SP, 0x10]
    lw r5,  [SP, 0x14]
    lw r6,  [SP, 0x18]
    lw r7,  [SP, 0x1C]
    lw r8,  [SP, 0x20]
    lw r9,  [SP, 0x24]
    lw r10, [SP, 0x28]
    lw r11, [SP, 0x2C]
    lw r12, [SP, 0x30]
    lw r13, [SP, 0x34]
    lw r14, [SP, 0x38]
    lw r15, [SP, 0x3C]
    lw r16, [SP, 0x40]
    lw r17, [SP, 0x44]
    lw r18, [SP, 0x48]
    lw r19, [SP, 0x4C]
    lw r20, [SP, 0x50]
    lw r21, [SP, 0x54]
    lw r22, [SP, 0x58]
    lw r23, [SP, 0x5C]
    lw r24, [SP, 0x60]
    lw r25, [SP, 0x64]
    lw r26, [SP, 0x68]
    lw r27, [SP, 0x6C]
    lw r28, [SP, 0x70]
    lw r29, [SP, 0x74]
    lw r30, [SP, 0x78]
    lw r31, [SP, 0x7C]
    addi	SP, 0x98
    rte
	nop
	nop

.text
.global invalid_cache
invalid_cache:
	cache 0x18, [r4,0]
	br r3	
	

