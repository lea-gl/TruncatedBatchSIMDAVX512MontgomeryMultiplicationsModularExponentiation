
#include "gmp_stuff.h"

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/////// GNU MP elements for Montgomery modular multiplication //////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void mpn_mod_mult(mp_limb_t *rop, const mp_limb_t *op1, const mp_limb_t *op2, const mp_limb_t *p_limbs, int nb_limbs){
	
	mp_limb_t c_limbs[2*nb_limbs];
	mp_limb_t q_limbs[nb_limbs+1];
	
	mpn_mul_n (c_limbs, op1, op2, nb_limbs); 
	mpn_tdiv_qr (q_limbs, rop, 0, c_limbs, (nb_limbs*2), p_limbs, nb_limbs); 
}

void mpn_mont_mul_red_1_(mp_limb_t *rop, mp_limb_t *op1, mp_limb_t *op2, const mp_limb_t *p_limbs, mp_limb_t mip0, int nb_limbs){
	
	mp_limb_t tmp_limbs[2*nb_limbs];
	
	mpn_mul_n (tmp_limbs, op1, op2, nb_limbs);
	
	if (mpn_redc_1(rop, tmp_limbs, p_limbs, nb_limbs, mip0) != 0)
		mpn_sub_n (rop, rop, p_limbs, nb_limbs);
}

// last Ysssouf's 08/02/2022
void mpn_mont_mul_red_1(mp_limb_t *rop, mp_limb_t *op1, mp_limb_t *op2, const mp_limb_t *p_limbs, mp_limb_t mip0, int nb_limbs){
	
	mp_limb_t tmp_limbs[2*nb_limbs];
	
	mpn_mul_n (tmp_limbs, op1, op2, nb_limbs);
	
	if (mpn_redc_1(rop, tmp_limbs, p_limbs, nb_limbs, mip0) != 0)
		mpn_sub_n (rop, rop, p_limbs, nb_limbs);
	else
		mpn_sub_n (tmp_limbs, rop, p_limbs, nb_limbs);
}


void mpn_mont_mul_red_n(mp_limb_t *rop, mp_limb_t *op1, mp_limb_t *op2, const mp_limb_t *p_limbs, mp_limb_t *mip_limbs, int nb_limbs){
	
	mp_limb_t tmp_limbs[2*nb_limbs];
	
	mpn_mul_n (tmp_limbs, op1, op2, nb_limbs);
	mpn_redc_n (rop, tmp_limbs, p_limbs, nb_limbs, mip_limbs);
}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//~ assumes 'rop' already initialised
void from_limbs_to_mpz_t(mpz_t rop, mp_limb_t *op, int op__nb_limbs){
	
	mpz_set_ui(rop, 0);
	
	if (op__nb_limbs == 0)
		return;
	
	int i, nb_dec;
	
	nb_dec = 8*sizeof(mp_limb_t);
	
	mpz_set_ui(rop, op[op__nb_limbs - 1]);
	
	for(i=(op__nb_limbs - 2); i >=0; i--){
		mpz_mul_2exp (rop, rop, nb_dec);
		mpz_add_ui (rop, rop, op[i]);
	}
}


//~ important: assumes allocation of 'nb_limbs' limbs already done for 'rop'
void copy_limbs(mp_limb_t *rop, mpz_t op, int nb_limbs){
	int i;
	const mp_limb_t *tmp;
	tmp = mpz_limbs_read(op);
	for(i=0; i<nb_limbs; i++)
		rop[i] = tmp[i];
}

void clean_limbs(mp_limb_t *op, int nb_limbs){
	for(int i=0; i<nb_limbs; i++)
		op[i] = 0;
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
////////////////////////////////////////////////////////////////////
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
