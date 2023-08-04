#include "mock_rectangle.h"
#include "inc/shape_container.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"




void setUp(void)

{

}



void tearDown(void)

{

}



void test_shape_container_init(void)

{



    uint16_t length = 4;

    uint16_t width = 3;





    rectangle_init_CMockExpect(21, length, width);





    shape_container_init(length, width);





}



void test_shape_container_calc_rect_is_square(void)

{



    uint16_t length = 4;

    uint16_t width = 4;

    uint16_t x_area = length * width;

    uint16_t x_perimeter = length + width + length + width;

    

   _Bool 

        x_is_square = 

                      1

                          ;





    rectangle_init_CMockExpect(39, length, width);

    rectangle_get_area_CMockExpectAndReturn(40, x_area);

    rectangle_get_perimeter_CMockExpectAndReturn(41, x_perimeter);

    rectangle_is_square_CMockExpectAndReturn(42, x_is_square);





    

   _Bool 

        is_square = shape_container_calc_rect(length, width);





    UnityAssertEqualNumber((UNITY_INT)((x_is_square)), (UNITY_INT)((is_square)), (

   ((void *)0)

   ), (UNITY_UINT)(48), UNITY_DISPLAY_STYLE_INT);

}



void test_shape_container_calc_rect_is_not_square(void)

{



    uint16_t length = 4;

    uint16_t width = 3;

    uint16_t x_area = length * width;

    uint16_t x_perimeter = length + width + length + width;

    

   _Bool 

        x_is_square = 

                      0

                           ;





    rectangle_init_CMockExpect(61, length, width);

    rectangle_get_area_CMockExpectAndReturn(62, x_area);

    rectangle_get_perimeter_CMockExpectAndReturn(63, x_perimeter);

    rectangle_is_square_CMockExpectAndReturn(64, x_is_square);





    

   _Bool 

        is_square = shape_container_calc_rect(length, width);





    UnityAssertEqualNumber((UNITY_INT)((x_is_square)), (UNITY_INT)((is_square)), (

   ((void *)0)

   ), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

}
