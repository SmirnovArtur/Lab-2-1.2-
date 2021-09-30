#include "pch.h"
#include "UlitkaLib.h"



TEST(Ulitka_Constructor, Default_Constructor) {
    Ulitka a;
    ASSERT_DOUBLE_EQ(1, a.get_R());
    ASSERT_DOUBLE_EQ(1, a.get_a());

}

TEST(Ulitka_Constructor, Default_Constructor_With_R) {
    Ulitka a(2);
    ASSERT_DOUBLE_EQ(2, a.get_R());
    ASSERT_DOUBLE_EQ(1, a.get_a());

}

TEST(Ulitka_Constructor, Init_Constructor) {
    Ulitka a(3, 4);
    ASSERT_DOUBLE_EQ(3, a.get_R());
    ASSERT_DOUBLE_EQ(4, a.get_a());

}

TEST(Ulitka_Setter, All_Setters) {
    Ulitka a, b(2), c(3, 4);

    a.set_R(2);
    a.set_a(3);
    ASSERT_DOUBLE_EQ(2, a.get_R());
    ASSERT_DOUBLE_EQ(3, a.get_a());

    b.set_R(3);
    b.set_a(6);
    ASSERT_DOUBLE_EQ(3, b.get_R());
    ASSERT_DOUBLE_EQ(6, b.get_a());

    c.set_R(0);
    c.set_a(3);
    ASSERT_DOUBLE_EQ(0, c.get_R());
    ASSERT_DOUBLE_EQ(3, c.get_a());
}

TEST(Ulitka_Methods, Len_Kriv_Area) { // №3, №4, №6
    const double err = 0.001;
    Ulitka a, b(2), c(3, 4);

    ASSERT_NEAR(2, a.len_to_beg(60), err); // №3
    ASSERT_NEAR(3, b.len_to_beg(60), err);
    ASSERT_NEAR(9.196, c.len_to_beg(30), err);

    ASSERT_NEAR(0.571, a.rkriv(60), err); // №4
    ASSERT_NEAR(0.379, b.rkriv(60), err);
    ASSERT_NEAR(0.162, c.rkriv(60), err);

    ASSERT_NEAR(9.425, a.area(), err); // №6
    ASSERT_NEAR(28.274, b.area(), err);
    ASSERT_NEAR(106.814, c.area(), err);
}

TEST(Ulitka_Methods, Type) { // №5
    Ulitka a1(3, 4), a2(1, 4), a3(2, 4), a4_1(3, 0), a4_2(0, 4), a5(0, 0);
    const char* type1 = "С петлёй", * type2 = "С перегибом", * type3 = "Кардиола", * type4 = "Окружность", * type5 = "Вырожденная";

    ASSERT_STREQ(type1, a1.type());
    ASSERT_STREQ(type2, a2.type());
    ASSERT_STREQ(type3, a3.type());
    ASSERT_STREQ(type4, a4_1.type());
    ASSERT_STREQ(type4, a4_2.type());
    ASSERT_STREQ(type5, a5.type());
}

TEST(Ulitka_Methods, Uravnenie) { // №7
    Ulitka a(3, 4), a_R0(0, 4), a_a0(3, 0), a_R0a0(0, 0);

    const char* c = "(x^2 + y^2 - 6.00*x)^2 - 16.00*(x^2 + y^2) = 0";
    const char* c_R0 = "(x^2 + y^2)^2 - 16.00*(x^2 + y^2) = 0";
    const char* c_a0 = "(x^2 + y^2 - 6.00*x)^2 = 0";
    const char* c_R0a0 = "(x^2 + y^2)^2 = 0";

    ASSERT_STREQ(c, a.uravnenie(0));
    ASSERT_STREQ(c_R0, a_R0.uravnenie(0));
    ASSERT_STREQ(c_a0, a_a0.uravnenie(0));
    ASSERT_STREQ(c_R0a0, a_R0a0.uravnenie(0));
}


int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
