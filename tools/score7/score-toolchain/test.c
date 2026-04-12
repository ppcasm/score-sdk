unsigned char ret_uc_0(void) { return 0; }
unsigned char ret_uc_1(void) { return 1; }

signed char ret_sc_0(void) { return 0; }
signed char ret_sc_m1(void) { return -1; }

unsigned short ret_us_0(void) { return 0; }
unsigned short ret_us_1(void) { return 1; }

signed short ret_ss_0(void) { return 0; }
signed short ret_ss_m1(void) { return -1; }

unsigned int ret_ui_0(void) { return 0; }
int ret_i_0(void) { return 0; }

long ret_l_0(void) { return 0; }
unsigned long ret_ul_0(void) { return 0; }

void ret_void(void) { }

unsigned char pass_uc(unsigned char x) { return x; }
unsigned short pass_us(unsigned short x) { return x; }
unsigned int pass_ui(unsigned int x) { return x; }

unsigned char local_uc(void)
{
    unsigned char x = 0;
    return x;
}

unsigned short local_us(void)
{
    unsigned short x = 0;
    return x;
}

unsigned int local_ui(void)
{
    unsigned int x = 0;
    return x;
}