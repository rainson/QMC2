/* 
 * File:   AlphaHarmonicOscillator.cpp
 * Author: jorgehog
 * 
 * Created on 26. juni 2012, 17:41
 */

#include "../../QMCheaders.h"

AlphaHarmonicOscillator::AlphaHarmonicOscillator(GeneralParams& gp) {
    VariationalParams dummyVar;
    dummyVar.alpha = 1;
    AlphaHarmonicOscillator(gp, dummyVar);
}

AlphaHarmonicOscillator::AlphaHarmonicOscillator(GeneralParams & gP, VariationalParams & vP)
: Orbitals(gP.n_p, gP.dim) {

    this->alpha = new double();
    this->k = new double();
    this->k2 = new double();
    this->exp_factor = new double();

    this->w = gP.systemConstant;
    set_parameter(vP.alpha, 0);
    get_qnums();

    basis_functions[0] = new HarmonicOscillator_0(k, k2, exp_factor);
    basis_functions[1] = new HarmonicOscillator_1(k, k2, exp_factor);
    basis_functions[2] = new HarmonicOscillator_2(k, k2, exp_factor);
    basis_functions[3] = new HarmonicOscillator_3(k, k2, exp_factor);
    basis_functions[4] = new HarmonicOscillator_4(k, k2, exp_factor);
    basis_functions[5] = new HarmonicOscillator_5(k, k2, exp_factor);
    basis_functions[6] = new HarmonicOscillator_6(k, k2, exp_factor);
    basis_functions[7] = new HarmonicOscillator_7(k, k2, exp_factor);
    basis_functions[8] = new HarmonicOscillator_8(k, k2, exp_factor);
    basis_functions[9] = new HarmonicOscillator_9(k, k2, exp_factor);
    basis_functions[10] = new HarmonicOscillator_10(k, k2, exp_factor);
    basis_functions[11] = new HarmonicOscillator_11(k, k2, exp_factor);
    basis_functions[12] = new HarmonicOscillator_12(k, k2, exp_factor);
    basis_functions[13] = new HarmonicOscillator_13(k, k2, exp_factor);
    basis_functions[14] = new HarmonicOscillator_14(k, k2, exp_factor);
    basis_functions[15] = new HarmonicOscillator_15(k, k2, exp_factor);
    basis_functions[16] = new HarmonicOscillator_16(k, k2, exp_factor);
    basis_functions[17] = new HarmonicOscillator_17(k, k2, exp_factor);
    basis_functions[18] = new HarmonicOscillator_18(k, k2, exp_factor);
    basis_functions[19] = new HarmonicOscillator_19(k, k2, exp_factor);
    basis_functions[20] = new HarmonicOscillator_20(k, k2, exp_factor);

    dell_basis_functions[0][0] = new dell_HarmonicOscillator_0_x(k, k2, exp_factor);
    dell_basis_functions[1][0] = new dell_HarmonicOscillator_0_y(k, k2, exp_factor);
    dell_basis_functions[0][1] = new dell_HarmonicOscillator_1_x(k, k2, exp_factor);
    dell_basis_functions[1][1] = new dell_HarmonicOscillator_1_y(k, k2, exp_factor);
    dell_basis_functions[0][2] = new dell_HarmonicOscillator_2_x(k, k2, exp_factor);
    dell_basis_functions[1][2] = new dell_HarmonicOscillator_2_y(k, k2, exp_factor);
    dell_basis_functions[0][3] = new dell_HarmonicOscillator_3_x(k, k2, exp_factor);
    dell_basis_functions[1][3] = new dell_HarmonicOscillator_3_y(k, k2, exp_factor);
    dell_basis_functions[0][4] = new dell_HarmonicOscillator_4_x(k, k2, exp_factor);
    dell_basis_functions[1][4] = new dell_HarmonicOscillator_4_y(k, k2, exp_factor);
    dell_basis_functions[0][5] = new dell_HarmonicOscillator_5_x(k, k2, exp_factor);
    dell_basis_functions[1][5] = new dell_HarmonicOscillator_5_y(k, k2, exp_factor);
    dell_basis_functions[0][6] = new dell_HarmonicOscillator_6_x(k, k2, exp_factor);
    dell_basis_functions[1][6] = new dell_HarmonicOscillator_6_y(k, k2, exp_factor);
    dell_basis_functions[0][7] = new dell_HarmonicOscillator_7_x(k, k2, exp_factor);
    dell_basis_functions[1][7] = new dell_HarmonicOscillator_7_y(k, k2, exp_factor);
    dell_basis_functions[0][8] = new dell_HarmonicOscillator_8_x(k, k2, exp_factor);
    dell_basis_functions[1][8] = new dell_HarmonicOscillator_8_y(k, k2, exp_factor);
    dell_basis_functions[0][9] = new dell_HarmonicOscillator_9_x(k, k2, exp_factor);
    dell_basis_functions[1][9] = new dell_HarmonicOscillator_9_y(k, k2, exp_factor);
    dell_basis_functions[0][10] = new dell_HarmonicOscillator_10_x(k, k2, exp_factor);
    dell_basis_functions[1][10] = new dell_HarmonicOscillator_10_y(k, k2, exp_factor);
    dell_basis_functions[0][11] = new dell_HarmonicOscillator_11_x(k, k2, exp_factor);
    dell_basis_functions[1][11] = new dell_HarmonicOscillator_11_y(k, k2, exp_factor);
    dell_basis_functions[0][12] = new dell_HarmonicOscillator_12_x(k, k2, exp_factor);
    dell_basis_functions[1][12] = new dell_HarmonicOscillator_12_y(k, k2, exp_factor);
    dell_basis_functions[0][13] = new dell_HarmonicOscillator_13_x(k, k2, exp_factor);
    dell_basis_functions[1][13] = new dell_HarmonicOscillator_13_y(k, k2, exp_factor);
    dell_basis_functions[0][14] = new dell_HarmonicOscillator_14_x(k, k2, exp_factor);
    dell_basis_functions[1][14] = new dell_HarmonicOscillator_14_y(k, k2, exp_factor);
    dell_basis_functions[0][15] = new dell_HarmonicOscillator_15_x(k, k2, exp_factor);
    dell_basis_functions[1][15] = new dell_HarmonicOscillator_15_y(k, k2, exp_factor);
    dell_basis_functions[0][16] = new dell_HarmonicOscillator_16_x(k, k2, exp_factor);
    dell_basis_functions[1][16] = new dell_HarmonicOscillator_16_y(k, k2, exp_factor);
    dell_basis_functions[0][17] = new dell_HarmonicOscillator_17_x(k, k2, exp_factor);
    dell_basis_functions[1][17] = new dell_HarmonicOscillator_17_y(k, k2, exp_factor);
    dell_basis_functions[0][18] = new dell_HarmonicOscillator_18_x(k, k2, exp_factor);
    dell_basis_functions[1][18] = new dell_HarmonicOscillator_18_y(k, k2, exp_factor);
    dell_basis_functions[0][19] = new dell_HarmonicOscillator_19_x(k, k2, exp_factor);
    dell_basis_functions[1][19] = new dell_HarmonicOscillator_19_y(k, k2, exp_factor);
    dell_basis_functions[0][20] = new dell_HarmonicOscillator_20_x(k, k2, exp_factor);
    dell_basis_functions[1][20] = new dell_HarmonicOscillator_20_y(k, k2, exp_factor);

    lapl_basis_functions[0] = new lapl_HarmonicOscillator_0(k, k2, exp_factor);
    lapl_basis_functions[1] = new lapl_HarmonicOscillator_1(k, k2, exp_factor);
    lapl_basis_functions[2] = new lapl_HarmonicOscillator_2(k, k2, exp_factor);
    lapl_basis_functions[3] = new lapl_HarmonicOscillator_3(k, k2, exp_factor);
    lapl_basis_functions[4] = new lapl_HarmonicOscillator_4(k, k2, exp_factor);
    lapl_basis_functions[5] = new lapl_HarmonicOscillator_5(k, k2, exp_factor);
    lapl_basis_functions[6] = new lapl_HarmonicOscillator_6(k, k2, exp_factor);
    lapl_basis_functions[7] = new lapl_HarmonicOscillator_7(k, k2, exp_factor);
    lapl_basis_functions[8] = new lapl_HarmonicOscillator_8(k, k2, exp_factor);
    lapl_basis_functions[9] = new lapl_HarmonicOscillator_9(k, k2, exp_factor);
    lapl_basis_functions[10] = new lapl_HarmonicOscillator_10(k, k2, exp_factor);
    lapl_basis_functions[11] = new lapl_HarmonicOscillator_11(k, k2, exp_factor);
    lapl_basis_functions[12] = new lapl_HarmonicOscillator_12(k, k2, exp_factor);
    lapl_basis_functions[13] = new lapl_HarmonicOscillator_13(k, k2, exp_factor);
    lapl_basis_functions[14] = new lapl_HarmonicOscillator_14(k, k2, exp_factor);
    lapl_basis_functions[15] = new lapl_HarmonicOscillator_15(k, k2, exp_factor);
    lapl_basis_functions[16] = new lapl_HarmonicOscillator_16(k, k2, exp_factor);
    lapl_basis_functions[17] = new lapl_HarmonicOscillator_17(k, k2, exp_factor);
    lapl_basis_functions[18] = new lapl_HarmonicOscillator_18(k, k2, exp_factor);
    lapl_basis_functions[19] = new lapl_HarmonicOscillator_19(k, k2, exp_factor);
    lapl_basis_functions[20] = new lapl_HarmonicOscillator_20(k, k2, exp_factor);
}

void AlphaHarmonicOscillator::get_qnums() {
    qnums = arma::zeros<arma::Mat<int> > (n2, dim);
    double n_x, n_y;

    int n_shells = (int) (0.5 * (sqrt(1 + 4 * n_p) - 1));

    int q = 0;
    for (int shell = 0; shell < n_shells; shell++) {

        n_x = 0;
        n_y = shell;

        for (int subshell_i = 0; subshell_i <= shell; subshell_i++) {
            qnums(q, 0) = n_x;
            qnums(q, 1) = n_y;

            n_x++;
            n_y--;

            q++;
        }
    }
}

double AlphaHarmonicOscillator::H(int n, double x) const {
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else if (n == 1) {
        return 2 * x;
    } else if (n == 2) {
        return 4 * x * x - 2;
    } else if (n == 3) {
        return 8 * x * x * x - 12 * x;
    } else if (n == 4) {
        double x2 = x*x;
        return 16 * x2 * x2 - 48 * x2 + 12;
    } else if (n == 5) {
        double x2 = x*x;
        return 32*x2*x2*x - 160*x2*x + 120*x;
    } else {
        std::cout << "Unsopported Hermite polynomial level: " << n << std::endl;
        exit(1);
    }
}

double AlphaHarmonicOscillator::get_variational_derivative(const Walker* walker, int n) {
    double dalpha, sq_w_over_a, exp_fac, H_fac, rij;
    int nij;

    dalpha = 0;
    sq_w_over_a = (*k) / (*alpha);

    for (int i = 0; i < n_p; i++) {
        exp_fac = -0.5 * w * walker->get_r_i2(i);

        for (int qnum = 0; qnum < n2; qnum++) {

            H_fac = 0;
            for (int j = 0; j < dim; j++) {
                rij = walker->r(i, j);
                nij = qnums(qnum, j);

                H_fac += rij * nij * H(nij - 1, (*k) * rij) / H(nij, (*k) * rij);
            }
            H_fac *= sq_w_over_a;


            dalpha += walker->inv(qnum, i)*(H_fac + exp_fac) * walker->phi(i, qnum);
        }
    }

    return dalpha;
}