/************************************************************************/
/*                                                                      */
/*     Copyright 2017-2018 by Ullrich Koethe                            */
/*                                                                      */
/*    This file is part of the XVIGRA image analysis library.           */
/*                                                                      */
/*    Permission is hereby granted, free of charge, to any person       */
/*    obtaining a copy of this software and associated documentation    */
/*    files (the "Software"), to deal in the Software without           */
/*    restriction, including without limitation the rights to use,      */
/*    copy, modify, merge, publish, distribute, sublicense, and/or      */
/*    sell copies of the Software, and to permit persons to whom the    */
/*    Software is furnished to do so, subject to the following          */
/*    conditions:                                                       */
/*                                                                      */
/*    The above copyright notice and this permission notice shall be    */
/*    included in all copies or substantial portions of the             */
/*    Software.                                                         */
/*                                                                      */
/*    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND    */
/*    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES   */
/*    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND          */
/*    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT       */
/*    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,      */
/*    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING      */
/*    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR     */
/*    OTHER DEALINGS IN THE SOFTWARE.                                   */
/*                                                                      */
/************************************************************************/

#include "unittest.hpp"
#include <xvigra/concepts.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xtensor.hpp>
#include <vector>
#include <type_traits>

namespace xvigra 
{
    std::int8_t test(...);

    template <class T,
              VIGRA_REQUIRE<std::is_integral<T>::value>>
    std::int16_t test(T);

    template <class T,
              VIGRA_REQUIRE<std::is_floating_point<T>::value>>
    std::int32_t test(T);

    TEST(concepts, concept_checking)
    {
        EXPECT_EQ(sizeof(test("a")), 1);
        EXPECT_EQ(sizeof(test(1)), 2);
        EXPECT_EQ(sizeof(test(1.0)), 4);
    }

    TEST(concepts, tensor_like)
    {
        EXPECT_TRUE(tensor_like<xt::xarray<double>>::value);
        EXPECT_TRUE((tensor_like<xt::xtensor<double,2>>::value));
        EXPECT_FALSE(tensor_like<std::vector<double>>::value);
    }

} // namespace xvigra
