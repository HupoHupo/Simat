#ifndef __SIMPLE_MATRIX_H__
#define __SIMPLE_MATRIX_H__

#include <string.h>
#include <math.h>
#include "api.h"

namespace QSpace
{
    template<typename Type, int rows, int cols>
    class Matrix
    {
    public:
        Matrix()
        {
            memset(data, 0, sizeof(data));
        }
        Matrix(const Matrix& mat)
        {
            memcpy(data, mat.data, sizeof(data));
        }
        Matrix(const Type* nums)
        {
            memcpy(data, nums, sizeof(data));
        }
        inline int Rows(void)
        {
            return rows;
        }
        inline int Cols(void)
        {
            return cols;
        }
        inline Matrix& operator << (const Type num)
        {
            Type& index = data[rows * cols - 1];

            index = -1;
            data[(int)++index] = num;
            return *this;
        }
        inline Matrix& operator , (const Type num)
        {
            Type& index = data[rows * cols - 1];
            if (index < rows * cols - 1) data[(int)++index] = num;
            return *this;
        }
        inline Type operator ()(int row, int col = 0) const
        {
            return data[row * cols + col];
        }

        inline Type& operator ()(int row, int col = 0)
        {
            return data[row * cols + col];
        }

        inline void AddFrom(const Matrix<Type, rows, cols>& mat1, const Matrix<Type, rows, cols>& mat2)
        {
            Type* p_data = data;
            const Type* p_mat1 = mat1.data;
            const Type* p_mat2 = mat2.data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat1++ + *p_mat2++;
                *p_data++ = *p_mat1++ + *p_mat2++;
                *p_data++ = *p_mat1++ + *p_mat2++;
                *p_data++ = *p_mat1++ + *p_mat2++;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat1++ + *p_mat2++;
            }
        }
        inline void AddFrom(const Matrix<Type, rows, cols>& mat, Type num)
        {
            Type* p_data = data;
            const Type* p_mat = mat.data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat++ + num;
                *p_data++ = *p_mat++ + num;
                *p_data++ = *p_mat++ + num;
                *p_data++ = *p_mat++ + num;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat++ + num;
            }
        }
        inline void AddBy(const Matrix<Type, rows, cols>& mat)
        {
            Type* p_data = data;
            const Type* p_mat = mat.data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ += *p_mat++;
                *p_data++ += *p_mat++;
                *p_data++ += *p_mat++;
                *p_data++ += *p_mat++;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ += *p_mat++;
            }
        }
        inline void AddBy(Type num)
        {
            Type* p_data = data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ += num;
                *p_data++ += num;
                *p_data++ += num;
                *p_data++ += num;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ += num;
            }
        }
        inline void SubFrom(const Matrix<Type, rows, cols>& mat1, const Matrix<Type, rows, cols>& mat2)
        {
            Type* p_data = data;
            const Type* p_mat1 = mat1.data;
            const Type* p_mat2 = mat2.data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat1++ - *p_mat2++;
                *p_data++ = *p_mat1++ - *p_mat2++;
                *p_data++ = *p_mat1++ - *p_mat2++;
                *p_data++ = *p_mat1++ - *p_mat2++;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat1++ - *p_mat2++;
            }
        }
        inline void SubFrom(const Matrix<Type, rows, cols>& mat, Type num)
        {
            Type* p_data = data;
            const Type* p_mat = mat.data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat++ - num;
                *p_data++ = *p_mat++ - num;
                *p_data++ = *p_mat++ - num;
                *p_data++ = *p_mat++ - num;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat++ - num;
            }
        }
        inline void SubFromZero(void)
        {
            Type* p_data1 = data;
            Type* p_data2 = data;
            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data1++ = -*p_data2++;
                *p_data1++ = -*p_data2++;
                *p_data1++ = -*p_data2++;
                *p_data1++ = -*p_data2++;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data1++ = -*p_data2++;
            }
        }
        inline void SubBy(const Matrix<Type, rows, cols>& mat)
        {
            Type* p_data = data;
            const Type* p_mat = mat.data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ -= *p_mat++;
                *p_data++ -= *p_mat++;
                *p_data++ -= *p_mat++;
                *p_data++ -= *p_mat++;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ -= *p_mat++;
            }
        }
        inline void SubBy(Type num)
        {
            Type* p_data = data;

            int cnt_div4 = (rows * cols) >> 2;

            while (cnt_div4-- > 0)
            {
                *p_data++ -= num;
                *p_data++ -= num;
                *p_data++ -= num;
                *p_data++ -= num;

            }
            cnt_div4 = (rows * cols) % 4;
            while (cnt_div4-- > 0)
            {
                *p_data++ -= num;
            }
        }
        template<int col_row>
        inline void MulFrom(const Matrix<Type, rows, col_row>& mat1, const Matrix<Type, col_row, cols>& mat2)
        {
            Type* sum = data;
            const Type* p_mat1 = mat1.data;
            const Type* p_mat2 = mat2.data;
            int row_cnt = 0;
            int col_cnt = 0;

            do
            {
                col_cnt = 0;
                do
                {
                    p_mat1 = mat1.data + row_cnt * col_row;
                    p_mat2 = mat2.data + col_cnt;
                    int cnt_div4 = col_row >> 2;
                    *sum = 0;
                    while (cnt_div4-- > 0)
                    {
                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;

                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;

                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;

                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;
                    }
                    cnt_div4 = col_row % 4;
                    while (cnt_div4-- > 0)
                    {
                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;
                    }
                    sum++;
                } while (++col_cnt < cols);
            } while (++row_cnt < rows);
        }
        inline void MulFrom(const Matrix<Type, rows, cols>& mat, Type scale)
        {
            Type* p_data = data;
            const Type* p_mat = mat.data;

            int cnt_div4 = rows * cols >> 2u;
            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat++ * scale;
                *p_data++ = *p_mat++ * scale;
                *p_data++ = *p_mat++ * scale;
                *p_data++ = *p_mat++ * scale;
            }
            cnt_div4 = rows * cols % 4u;
            while (cnt_div4-- > 0)
            {
                *p_data++ = *p_mat++ * scale;
            }
        }
        inline void MulBy(const Matrix<Type, cols, cols>& mat2)
        {
            Type* sum = data;
            const Matrix<Type, rows, cols> mat1(*this);
            const Type* p_mat1 = mat1.data;
            const Type* p_mat2 = mat2.data;
            int row_cnt = 0;
            int col_cnt = 0;

            do
            {
                col_cnt = 0;
                do
                {
                    p_mat1 = mat1.data + row_cnt * cols;
                    p_mat2 = mat2.data + col_cnt;
                    int cnt_div4 = cols >> 2u;
                    *sum = 0;
                    while (cnt_div4-- > 0)
                    {
                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;

                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;

                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;

                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;
                    }
                    cnt_div4 = cols % 4u;
                    while (cnt_div4-- > 0)
                    {
                        *sum += *p_mat1 * *p_mat2;
                        p_mat2 += cols;
                        ++p_mat1;
                    }
                    sum++;
                } while (++col_cnt < cols);
            } while (++row_cnt < rows);
        }
        inline void MulBy(Type scale)
        {
            Type tmp;
            Type* p_data = data;

            int cnt_div4 = rows * cols >> 2u;
            while (cnt_div4-- > 0)
            {
                tmp = *p_data;
                *p_data++ = tmp * scale;
                tmp = *p_data;
                *p_data++ = tmp * scale;
                tmp = *p_data;
                *p_data++ = tmp * scale;
                tmp = *p_data;
                *p_data++ = tmp * scale;
            }
            cnt_div4 = rows * cols % 4u;
            while (cnt_div4-- > 0)
            {
                tmp = *p_data;
                *p_data++ = tmp * scale;
            }
        }
        inline bool InvFrom(const Matrix<Type, cols, cols>& mat)
        {
            Type tmp1;
            Type tmp2;
            Type* p_mat1;
            Type* p_mat2;
            int pivot_col = 0;
            int pivot_row = 0;
            Matrix<Type, cols, cols> mat_tmp(mat);

            SetIdentity();

            for (pivot_col = 0; pivot_col < cols; ++pivot_col)
            {
                p_mat1 = mat_tmp.data + pivot_col * (cols + 1);
                pivot_row = pivot_col;
                while (pivot_row < rows)
                {
                    if (IsZero(*p_mat1) == false) break;
                    else if (++pivot_row == rows) return false;

                    p_mat1 += cols;
                }

                if (pivot_row != pivot_col)
                {

                    p_mat1 = mat_tmp.data + pivot_col * (cols + 1);
                    p_mat2 = p_mat1 + (pivot_row - pivot_col) * cols;

                    for (int i = pivot_col; i < cols; ++i)
                    {
                        tmp1 = *p_mat1;
                        *p_mat1++ = *p_mat2;
                        *p_mat2++ = tmp1;
                    }

                    p_mat1 = data + pivot_col * cols;
                    p_mat2 = p_mat1 + (pivot_row - pivot_col) * cols;

                    for (int i = 0; i < cols; ++i)
                    {
                        tmp1 = *p_mat1;
                        *p_mat1++ = *p_mat2;
                        *p_mat2++ = tmp1;
                    }
                }

                p_mat1 = mat_tmp.data + pivot_col * (cols + 1);
                p_mat2 = data + pivot_col * cols;
                tmp1 = *p_mat1;

                for (int i = pivot_col; i < cols; ++i)
                {
                    tmp2 = *p_mat1;
                    *p_mat1++ = tmp2 / tmp1;
                }
                for (int i = 0; i < cols; ++i)
                {
                    tmp2 = *p_mat2;
                    *p_mat2++ = tmp2 / tmp1;
                }
                for (int i = 0; i < cols; ++i)
                {
                    if (i != pivot_col)
                    {
                        p_mat1 = mat_tmp.data + pivot_col * (cols + 1);
                        p_mat2 = p_mat1 + (i - pivot_col) * cols;
                        tmp1 = *p_mat2;
                        for (int j = pivot_col; j < cols; ++j)
                        {
                            tmp2 = *p_mat2;
                            *p_mat2++ = tmp2 - *p_mat1++ * tmp1;
                        }

                        Type* p_out1 = data + pivot_col * cols;
                        Type* p_out2 = p_out1 + (i - pivot_col) * cols;
                        for (int j = 0; j < cols; ++j)
                        {
                            tmp2 = *p_out2;
                            *p_out2++ = tmp2 - *p_out1++ * tmp1;
                        }
                    }
                }
            }
            return true;
        }
        inline void TransFrom(const Matrix<Type, cols, rows> mat)
        {
            int row = 0;
            Type* p_this = data;
            const Type* p_data = mat.data;

            do
            {
                p_data = mat.data + row;
                int cnt_div4 = cols >> 2u;
                while (cnt_div4-- > 0)
                {
                    *p_this++ = *p_data;
                    p_data += rows;

                    *p_this++ = *p_data;
                    p_data += rows;

                    *p_this++ = *p_data;
                    p_data += rows;

                    *p_this++ = *p_data;
                    p_data += rows;
                }
                cnt_div4 = cols % 4u;
                while (cnt_div4-- > 0)
                {
                    *p_this++ = *p_data;
                    p_data += rows;
                }
            } while (++row < rows);
        }

        inline Type Norm(int row = rows, int col = 0) const
        {
            const Type* tmp = data + col;
            Type norm = 0;

            for (int i = 0; i < row; ++i)
            {
                norm += *tmp * *tmp;
                tmp += cols;
            }

            return sqrt((double)norm);
        }
        inline Type Norm2(int row = rows, int col = 0) const
        {
            const Type* tmp = data + col;
            Type norm = 0;

            for (int i = 0; i < row; ++i)
            {
                norm += *tmp * *tmp;
                tmp += cols;
            }

            return norm;
        }
        inline void Normlize(void)
        {
            MulBy((Type)1 / Norm());
        }
        inline void SetZeros(void)
        {
            memset(data, 0, sizeof(data));
        }
        inline void SetOnes(void)
        {
            Type* tmp = data;
            int cnt_div4 = rows * cols >> 2;
            while (cnt_div4-- > 0)
            {
                *tmp++ = 1;
                *tmp++ = 1;
                *tmp++ = 1;
                *tmp++ = 1;
            }
            cnt_div4 = rows * cols % 4;
            while (cnt_div4-- > 0)
            {
                *tmp++ = 1;
            }
        }
        template<int rows_b, int cols_b>
        inline void SetBlock(int row, int col, const Matrix<Type, rows_b, cols_b>& mat)
        {
            int row_cnt = rows - row > rows_b ? rows_b : rows - row;
            int col_cnt = cols - col > cols_b ? cols_b : cols - col;

            if (row_cnt < 0 || col_cnt < 0) return;

            int cnt_div4;
            const Type* p_mat = mat.data;
            Type* p_this;

            while (row_cnt-- > 0)
            {
                cnt_div4 = col_cnt >> 2u;
                p_this = data + row * cols + col;
                row++;

                while (cnt_div4-- > 0)
                {
                    *p_this++ = *p_mat++;
                    *p_this++ = *p_mat++;
                    *p_this++ = *p_mat++;
                    *p_this++ = *p_mat++;
                }

                cnt_div4 = col_cnt % 4u;

                while (cnt_div4-- > 0)
                {
                    *p_this++ = *p_mat++;
                }
            }
        }
        template<int rows_b, int cols_b>
        inline Matrix<Type, rows_b, cols_b> GetBlock(int row, int col) const
        {
            int row_cnt = rows - row > rows_b ? rows_b : rows - row;
            int col_cnt = cols - col > cols_b ? cols_b : cols - col;

            Matrix<Type, rows_b, cols_b> mat;
            if (row_cnt < 0 || col_cnt < 0) return mat;

            const Type* p_this = data;
            Type* p_mat = mat.data;
            int cnt_div4;

            while (row_cnt-- > 0)
            {
                cnt_div4 = col_cnt >> 2u;
                p_this = data + row * cols + col;
                row++;

                while (cnt_div4-- > 0)
                {
                    *p_mat++ = *p_this++;
                    *p_mat++ = *p_this++;
                    *p_mat++ = *p_this++;
                    *p_mat++ = *p_this++;
                }

                cnt_div4 = col_cnt % 4u;

                while (cnt_div4-- > 0)
                {
                    *p_mat++ = *p_this++;
                }
            }

            return mat;
        }
        inline Matrix<Type, rows, rows> AsDiagonal(int col = 0) const
        {
            Matrix<Type, rows, rows> mat;
            mat.SetZeros();
            const Type* p_this = data + col;
            Type* p_mat = mat.data;

            int cnt_div4 = rows >> 2u;

            while (cnt_div4-- > 0)
            {
                *p_mat = *p_this;
                p_this += cols;
                p_mat += rows + 1;

                *p_mat = *p_this;
                p_this += cols;
                p_mat += rows + 1;

                *p_mat = *p_this;
                p_this += cols;
                p_mat += rows + 1;

                *p_mat = *p_this;
                p_this += cols;
                p_mat += rows + 1;
            }

            cnt_div4 = rows % 4u;
            while (cnt_div4-- > 0)
            {
                *p_mat = *p_this;
                p_this += cols;
                p_mat += rows + 1;
            }

            return mat;
        }
        inline Matrix<Type, rows, 1> Diagonal(void) const
        {
            Matrix<Type, cols, 1> mat;

            mat.SetZeros();
            const Type* p_this = data;
            Type* p_mat = mat.data;

            int cnt_div4 = rows >> 2u;

            while (cnt_div4-- > 0)
            {
                *p_mat++ = *p_this;
                p_this += cols + 1;

                *p_mat++ = *p_this;
                p_this += cols + 1;

                *p_mat++ = *p_this;
                p_this += cols + 1;

                *p_mat++ = *p_this;
                p_this += cols + 1;
            }

            cnt_div4 = rows % 4u;
            while (cnt_div4-- > 0)
            {
                *p_mat++ = *p_this;
                p_this += cols + 1;
            }

            return mat;
        }
        inline void SetIdentity(int row = 0, int col = 0, int cnt = cols + 1)
        {
            cnt = cnt < rows - row ? cnt : rows - row;
            cnt = cnt < cols - col ? cnt : cols - col;
            if (cnt < 0) return;

            Type* p_data = data + row * cols + col;
            memset(data, 0, sizeof(data));

            int cnt_div4 = cnt >> 2u;
            while (cnt_div4-- > 0)
            {
                *p_data = 1;
                p_data += cols + 1;
                *p_data = 1;
                p_data += cols + 1;
                *p_data = 1;
                p_data += cols + 1;
                *p_data = 1;
                p_data += cols + 1;
            }
            cnt_div4 = cnt % 4u;
            while (cnt_div4-- > 0)
            {
                *p_data = 1;
                p_data += cols + 1;
            }
        }
        inline Matrix<Type, rows, cols> Inverse(void) const
        {
            Matrix<Type, rows, cols> mat_out;
            mat_out.InvFrom(*this);
            return mat_out;
        }
        inline Matrix<Type, cols, rows> Transpose(void) const
        {
            Matrix<Type, cols, rows> mat_out;
            mat_out.TransFrom(*this);
            return mat_out;
        }

        inline Matrix<Type, 3, 3> SkewMat(int row = 0, int col = 0) const
        {
            Matrix<Type, 3, 3> mat;
            mat.SetZeros();

            if (row + 3 > rows) return mat;
            if (col > cols) return mat;

            const Type* p_data = data + row * cols + col;

            mat(1, 2) = -*p_data;
            mat(2, 1) = +*p_data;

            p_data += cols;
            mat(2, 0) = -*p_data;
            mat(0, 2) = +*p_data;

            p_data += cols;
            mat(0, 1) = -*p_data;
            mat(1, 0) = +*p_data;

            return mat;
        }

        inline Matrix<Type, 3, 3> SkewEyeMat(int row = 0, int col = 0) const
        {
            Matrix<Type, 3, 3> mat;
            mat.SetIdentity();

            if (row + 3 > rows) return mat;
            if (col > cols) return mat;

            const Type* p_data = data + row * cols + col;

            mat(1, 2) = -*p_data;
            mat(2, 1) = +*p_data;

            p_data += cols;
            mat(2, 0) = -*p_data;
            mat(0, 2) = +*p_data;

            p_data += cols;
            mat(0, 1) = -*p_data;
            mat(1, 0) = +*p_data;

            return mat;
        }

        inline void Print(const char* format = "% .3e", uint8_t port = DEBUG_PORT) const
        {
            const Type* p_data = data;
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    QPrint(port, format, *p_data++);
                    QPrint(port, " ");
                }
                QPrint(port, "\r\n");
            };
        }

        inline void Print(uint8_t port = DEBUG_PORT, const char* format = "% .3e") const
        {
            const Type* p_data = data;
            for (int i = 0; i < rows; ++i)
            {
                for (int j = 0; j < cols; ++j)
                {
                    QPrint(port, format, *p_data++);
                    QPrint(port, " ");
                }
                QPrint(port, "\r\n");
            };
        }
        void ReadElement(Type* buffer, int size = cols * rows)
        {
            if (size > cols* rows) size = cols * rows;
            memcpy(buffer, data, size * sizeof(Type));
        }
    private:
        inline bool IsZero(Type num)
        {
            if ((num > (Type)0.0 ? num : -num) < (Type)1e-49) return true;
            else return false;
        }
    public:
        Type data[rows * cols];
    };
    template<typename Type, int rows, int cols>
    inline Matrix<Type, rows, cols> operator + (Matrix<Type, rows, cols> mat1, const Matrix<Type, rows, cols>& mat2)
    {
        mat1.AddBy(mat2);
        return mat1;
    }
    template<typename Type, int rows, int cols>
    inline void operator += (Matrix<Type, rows, cols>& mat1, const Matrix<Type, rows, cols>& mat2)
    {
        mat1.AddBy(mat2);
    }
    template<typename Type, int rows, int cols>
    inline void operator += (Matrix<Type, rows, cols>& mat1, Type num)
    {
        mat1.AddBy(num);
    }
    template<typename Type, int rows, int cols>
    inline Matrix<Type, rows, cols> operator - (Matrix<Type, rows, cols> mat1, const Matrix<Type, rows, cols>& mat2)
    {
        mat1.SubBy(mat2);
        return mat1;
    }
    template<typename Type, int rows, int cols>
    inline Matrix<Type, rows, cols> operator - (Matrix<Type, rows, cols> mat1)
    {
        mat1.SubFromZero();
        return mat1;
    }
    template<typename Type, int rows, int cols>
    inline void operator -= (Matrix<Type, rows, cols>& mat1, const Matrix<Type, rows, cols>& mat2)
    {
        mat1.SubBy(mat2);
    }
    template<typename Type, int rows, int cols>
    inline void operator -= (Matrix<Type, rows, cols>& mat1, Type num)
    {
        mat1.SubBy(num);
    }
    template<typename Type, int rows, int cols_rows, int cols>
    inline Matrix<Type, rows, cols> operator * (Matrix<Type, rows, cols_rows> mat1, const Matrix<Type, cols_rows, cols>& mat2)
    {
        Matrix<Type, rows, cols> mat3;
        mat3.MulFrom(mat1, mat2);
        return mat3;
    }
    template<typename Type, int rows, int cols>
    inline Matrix<Type, rows, cols> operator * (const Matrix<Type, rows, cols>& mat1, Type num)
    {
        Matrix<Type, rows, cols> mat2;
        mat2.MulFrom(mat1, num);
        return mat2;
    }
    template<typename Type, int rows, int cols>
    inline void operator *= (Matrix<Type, rows, cols>& mat1, const Matrix<Type, cols, cols>& mat2)
    {
        mat1.MulBy(mat2);
    }
    template<typename Type, int rows, int cols>
    inline void operator *= (Matrix<Type, rows, cols>& mat, Type num)
    {
        mat.MulBy(num);
    }
    template<typename Type, int rows, int cols>
    inline Matrix<Type, rows, cols> operator / (const Matrix<Type, rows, cols>& mat1, Type num)
    {
        Matrix<Type, rows, cols> mat2;
        mat2.MulFrom(mat1, (Type)1 / num);
        return mat2;
    }
    typedef Matrix<double, 3, 1> Vector3d;
    typedef Matrix<double, 3, 3> Matrix3d;
}
#endif
