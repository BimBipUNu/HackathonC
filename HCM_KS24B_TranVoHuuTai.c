#include <stdio.h>

int main()
{
    int chose = 0;
    int active = 0;
    int size = 0;
    int a[100]; 
    while (chose != 11)
    {
        printf("\n============MENU===========\n");
        printf("1. Nhập số phần tử và giá trị cho mảng\n");
        printf("2. In ra giá trị các phần tử trong mảng\n");
        printf("3. Đếm số lượng các số nguyên tố có trong mảng\n");
        printf("4. Tìm giá trị nhỏ thứ hai trong mảng\n");
        printf("5. Thêm một phần tử vào trong mảng\n");
        printf("6. Xóa phần tử \n");
        printf("7. Sắp xếp mảng theo thứ tự giảm dần (Insertion sort)\n");
        printf("8. Tìm kiếm xem phần tử có tồn tại trong mảng hay không (Binary search)\n");
        printf("9. Xóa toàn bộ phần tử trùng lặp trong mảng và hiển thị toàn bộ phần tử độc nhất có ở trong mảng\n");
        printf("10. Đảo ngược thứ tự của các phần tử có trong mảng\n");
        printf("11. Thoát\n");
        printf("===========================\n");
        printf("Lựa chọn của bạn: ");
        scanf("%d", &chose);
        if (chose == 1)
        {
            active = 1;
            printf("Nhập số lượng phần tử: ");scanf("%d", &size);
            for (int i = 0; i < size; i++)
            {
                printf("Nhập phần tử thứ %d: ", i);
                scanf("%d", &a[i]);
            }
            continue;
        } else if (chose != 1 && active == 0)
        {
            printf("Chưa có dữ liệu\n");
            continue;
        }

        int count = 0;
        int countNgTo = 0;
        int min;
        int theSecondMin;
        int addIndex;
        int addNumber;
        int del;
        int start;
        int end;
        int findNum;
        int indexADS = 0;

        switch (chose)
        {
            case 1:
                printf("Nhập số lượng phần tử: ");scanf("%d", &size);
                for (int i = 0; i < size; i++)
                {
                    printf("Nhập phần tử thứ %d: ", i);scanf("%d", &a[i]);
                }
                break;
            case 2:
                printf("Các phần tử trong mảng: ");
                for (int i = 0; i < size; i++)
                {
                    if (i == size - 1)
                    {
                        printf("arr[%d]=%d", i, a[i]);
                        break;
                    }
                    printf("arr[%d]=%d, ", i, a[i]);
                }
                printf("\n");
                break;
            case 3:
                countNgTo = 0;
                for (int i = 0; i < size; i++)
                {
                    if (a[i] < 2)
                    {
                        continue;
                    }
                    count = 0;
                    for (int j = 2; j * j <= a[i]; j++)
                    {
                        if (a[i] % j == 0) {
                            count++;
                        }
                    }
                    if (count == 0)
                    {
                        countNgTo++;
                    }
                }
                printf("Số lượng số Nguyên tố có trong mảng: %d\n", countNgTo);
                break;
            case 4:
                if (size < 2)
                {
                    printf("Không đủ phần tử để tìm giá trị nhỏ thứ hai\n");
                    break;
                }
                min = a[0];
                theSecondMin = a[1];
                if (min > theSecondMin)
                {
                    int temp = min;
                    min = theSecondMin;
                    theSecondMin = temp;
                }
                for (int i = 2; i < size; i++)
                {
                    if (a[i] < min)
                    {
                        theSecondMin = min;
                        min = a[i];
                    } else if (a[i] < theSecondMin && a[i] != min)
                    {
                        theSecondMin = a[i];
                    }
                }
                printf("Giá trị nhỏ thứ hai trong mảng: %d\n", theSecondMin);
                break;
            case 5:
                printf("Nhập phần tử muốn thêm vào mảng: ");scanf("%d", &addNumber);
                printf("Nhập vị trí muốn thêm phần tử: ");scanf("%d", &addIndex);
                for (int i = size; i >= addIndex; i--)
                {
                    a[i] = a[i - 1];
                }
                a[addIndex - 1] = addNumber;
                size++;
                break;
            case 6:
                printf("Vị trí phần tử muốn xóa: ");scanf("%d", &del);
                for (int i = del - 1; i < size - 1; i++)
                {
                    a[i] = a[i + 1];
                }
                size--;
                break;
            case 7:
                for (int i = 1; i < size; i++)
                {
                    int key = a[i];
                    int j = i - 1;
                    while (j >= 0 && a[j] < key)
                    {
                        a[j + 1] = a[j];
                        j--;
                    }
                    a[j + 1] = key;
                }
                break;
            case 8:
                printf("Nhập phần tử cần tìm: ");
                scanf("%d", &findNum);
                for (int i = 0; i < size - 1; i++)
                {
                    for (int j = 0; j < size - i - 1; j++)
                    {
                        if (a[j] < a[j + 1]) {
                            int temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }
                start = 0;
                end = size - 1;
                while (start <= end)
                {
                    int mid = start + (end - start) / 2;
                    if (a[mid] == findNum) {
                        printf("Phần tử %d tồn tại trong mảng\n", findNum);
                        break;
                    } else if (a[mid] < findNum) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
                if (start > end)
                {
                    printf("Không có phần tử %d trong mảng\n", findNum);
                }
                break;
            case 9:
                for (int i = 0; i < size; i++)
                {
                    for (int j = i + 1; j < size; j++)
                    {
                        if (a[i] == a[j]) {
                            for (int k = j; k < size - 1; k++)
                            {
                                a[k] = a[k + 1];
                            }
                            size--;
                            j--;
                        }
                    }
                }
                printf("Các phần tử độc nhất trong mảng: ");
                for (int i = 0; i < size; i++)
                {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            case 10:
                for (int i = 0; i < size / 2; i++)
                {
                    int temp = a[i];
                    a[i] = a[size - i - 1];
                    a[size - i - 1] = temp;
                }
                break;
        }
    }
    printf("Thoát chương trình\n");
}