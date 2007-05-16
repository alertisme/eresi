/**
 * @file asm_operand_fetch.c
 * $Id: asm_operand_fetch_ydest.c,v 1.1 2007-05-09 17:39:35 heroine Exp $
 */

#include <libasm.h>
#include <libasm-int.h>

/**
 *
 *
 */

int     asm_operand_fetch_ydest(asm_operand *operand, u_char *opcode, int otype, 
				asm_processor *proc)
{
  operand->type = ASM_OTYPE_YDEST;
  operand->content = ASM_OP_BASE | ASM_OP_REFERENCE;
  operand->base_reg = ASM_REG_EDI;
  operand->regset = asm_proc_opsize(proc) ? ASM_REGSET_R16 : ASM_REGSET_R32;
  operand->prefix = ASM_PREFIX_ES;
  return (0);
}