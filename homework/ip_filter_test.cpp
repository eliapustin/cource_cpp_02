#include <cassert>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>


int main(int argc, char const *argv[])
{
    std::vector<std::vector<std::string>> ip_pool = {{"1", "2", "3", "4"}, {"2", "4", "7", "5"}, {"2", "8", "9", "3"}, {"1", "1", "5", "6"}, {"1", "2", "2", "7"}};
    std::vector<std::vector<std::string>> ip_pool_sorted;
    std::vector<std::vector<std::list<std::vector<std::string>> > > ip_pools_handle(4, std::vector<std::list<std::vector<std::string>> > (255) );

    for (auto ip : ip_pool) {
        int i = 0;
        for (std::vector<std::string>::const_iterator ip_part = ip.cbegin(); ip_part != ip.cend(); ++ip_part) {
        // for (auto ip_part : ip) {
            int ip_part_as_int = std::stoi(*ip_part);
            ip_pools_handle.at(i).at(ip_part_as_int).push_back(ip);
            
            if (ip_part != ip.cbegin()) {
                std::cout << ".";
            }
            std::cout << *ip_part;
            i++;
        }
        std::cout << std::endl;
    }

    std::cout << "Before sorting:" << std::endl;
    for (const auto& vec : ip_pools_handle.at(0)) {        
        if (!vec.empty()) {
            for (const auto& list : vec) {
                for (const auto& ip : list) {
                    for (const auto& ip_part : ip) {
                        // for (auto ip_part : ip) {
                            std::cout << ip_part << ".";
                        }
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }

    //1
    for (auto &ip : ip_pools_handle.at(0)) {
        if (!ip.empty()) {
            ip.sort([](const std::vector<std::string> &a, const std::vector<std::string> &b) {
                unsigned long a_seg = std::stoi(a.at(0)) * 1000000000 + std::stoi(a.at(1)) * 1000000 + std::stoi(a.at(2)) * 1000 + std::stoi(a.at(3)) ;
                unsigned long b_seg = std::stoi(b.at(0)) * 1000000000 + std::stoi(b.at(1)) * 1000000 + std::stoi(b.at(2)) * 1000 + std::stoi(b.at(3)) ;
                    // for (int i = 1; i < 4; ++i) {
                    //     int a_seg_cur = std::stoi(a.at(i));
                    //     int b_seg_cur = std::stoi(b.at(i));
                    //     int a_seg_prev = std::stoi(a.at(i-1));
                    //     int b_seg_prev = std::stoi(b.at(i-1));
                    //     return ((a_seg_prev == b_seg_prev) && (b_seg_cur > a_seg_cur));
                    // }
                return b_seg > a_seg;
            });
        }
    }
    
    std::cout << "Sorted by Vector Size:" << std::endl;
    for (const auto& vec : ip_pools_handle.at(0)) {        
        if (!vec.empty()) {
            for (const auto& list : vec) {
                for (const auto& ip : list) {
                    for (const auto& ip_part : ip) {
                        // for (auto ip_part : ip) {
                            std::cout << ip_part << ".";
                        }
                }
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}

// #include <iostream>
// #include <list>
// #include <vector>
// #include <string>
// #include <algorithm>

// int main() {
//     // Example list of vector of strings
//     std::vector<std::list<std::vector<std::string>>> vectorofListOfVectors{
//         {{"1", "2", "3", "4"},
//         {"2", "5", "4", "7"}},
//         {{"1", "4", "7", "8"},
//         {"4", "7", "5", "4"},
//         {"4", "6", "9", "3"}}
//     };
    
//     std::cout << "Before sorting:" << std::endl;
//     for (const auto& vec : vectorofListOfVectors.at(1)) {
//         for (const auto& str : vec) {
//             std::cout << str << " ";
//         }
//         std::cout << std::endl;
//     }

//     // Criterion 1: Sorting based on the vector's size
//     if (!vectorofListOfVectors.at(1).empty()) {
//         vectorofListOfVectors.at(1).sort([](const std::vector<std::string>& a, const std::vector<std::string>& b) {
//                     int a_seg = std::stoi(a.at(1));
//                     int b_seg = std::stoi(b.at(1));
//                     return b_seg > a_seg;
//         });
//     }

//     std::cout << "Sorted by Vector Size:" << std::endl;
//     for (const auto& vec : vectorofListOfVectors.at(1)) {
//         for (const auto& str : vec) {
//             std::cout << str << " ";
//         }
//         std::cout << std::endl;
//     }

//     // Add more criteria as needed.
    
//     return 0;
// }
