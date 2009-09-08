/**
** @file asm_arm_blx1.c
** @ingroup a-instrs
*/
#include "libasm.h"

int     asm_arm_blx1(asm_instr * ins, u_char * buf, u_int len,
                    asm_processor * proc)
{
  struct s_arm_decode_branch1 opcode;
  struct s_asm_proc_arm *inter;

  LIBASM_PROFILE_FIN();

  inter = proc->internals;
  arm_convert_branch1(&opcode, buf);

  ins->instr = inter->branch1_table[(opcode.l_h << 4) | opcode.cond];

  ins->name = ins->proc->instr_table[ins->instr];

  ins->type = ASM_TYPE_CALLPROC; /* Imperative call proc */

  ins->nb_op = 1;

  /* Decode operands */
  ins->op[0].imm = opcode.signed_imm;
  asm_arm_op_fetch(&ins->op[0], buf, opcode.l_h ? ASM_ARM_OTYPE_DISP_HALF : ASM_ARM_OTYPE_DISP, ins);

  LIBASM_PROFILE_FOUT(4);
}