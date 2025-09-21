#include "easyfind.hpp"

int main()
{
    int arr[] = {2, 8, 343, -23, 23, 543};
    std::vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));

    try
    {
        int res = easyfind(v, 23);
        std::cout << res << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}