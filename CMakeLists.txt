cmake_minimum_required(VERSION 3.21)
project(dsa)
find_program(CCACHE_PROGRAM ccache)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

if(CCACHE_PROGRAM)
    MESSAGE("CCACHE support enabled")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK "${CCACHE_PROGRAM}")
endif()

set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_BUILD_TYPE "Debug")

#add_compile_options(-fsanitize=address)
#add_compile_options(-fsanitize=undefined)
#add_compile_options(-fsanitize=leak)

# add_compile_definitions(DEBUG)
function(add_code name path)
    add_executable(${name} ${path})
    target_link_libraries(${name})
    target_include_directories(${name} PRIVATE src/)
    target_compile_definitions(${name} PRIVATE DEBUG=1)
endfunction()

set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

add_code(HelloWorld "src/HelloWorld.cpp")

#add_code(BW94_Q1 "src/leetcode/biweekly/BW94_Q1.cpp")
#add_code(BW94_Q2 "src/leetcode/biweekly/BW94_Q2.cpp")
#add_code(BW94_Q3 "src/leetcode/biweekly/BW94_Q3.cpp")
#add_code(BW94_Q4 "src/leetcode/biweekly/BW94_Q4.cpp")

#add_code(W325_Q1 "src/leetcode/weekly/W325_Q1.cpp")
#add_code(W325_Q2 "src/leetcode/weekly/W325_Q2.cpp")
#add_code(W325_Q3 "src/leetcode/weekly/W325_Q3.cpp")
#add_code(W325_Q4 "src/leetcode/weekly/W325_Q4.cpp")

#add_code(W326_Q1 "src/leetcode/weekly/W326/W326_Q1.cpp")
#add_code(W326_Q2 "src/leetcode/weekly/W326/W326_Q2.cpp")
#add_code(W326_Q3 "src/leetcode/weekly/W326/W326_Q3.cpp")
#add_code(W326_Q4 "src/leetcode/weekly/W326/W326_Q4.cpp")

#add_code(W352_Q1 "src/leetcode/weekly/W352/W352_Q1.cpp")
#add_code(W352_Q2 "src/leetcode/weekly/W352/W352_Q2.cpp")
#add_code(W352_Q3 "src/leetcode/weekly/W352/W352_Q3.cpp")
#add_code(W352_Q4 "src/leetcode/weekly/W352/W352_Q4.cpp")

add_code(BW109_Q1 "src/leetcode/biweekly/BW109/BW109_Q1.cpp")
add_code(BW109_Q2 "src/leetcode/biweekly/BW109/BW109_Q2.cpp")
add_code(BW109_Q3 "src/leetcode/biweekly/BW109/BW109_Q3.cpp")
add_code(BW109_Q4 "src/leetcode/biweekly/BW109/BW109_Q4.cpp")

add_code(ValidParentheses "src/patterns/ValidParentheses.cpp")
add_code(BinarySearch "src/patterns/BinarySearch.cpp")
add_code(FloodFill "src/patterns/FloodFill.cpp")
add_code(LCA "src/patterns/LCA.cpp")


add_code(AddBinary "src/patterns/binary/AddBinary.cpp")
add_code(FindDuplicateNumber "src/patterns/binary/FindDuplicateNumber.cpp")
add_code(CountingBits "src/patterns/binary/CountingBits.cpp")
add_code(HammingWeight "src/patterns/binary/HammingWeight.cpp")
add_code(ReverseBits "src/patterns/binary/ReverseBits.cpp")
add_code(SingleNumber "src/patterns/binary/SingleNumber.cpp")
add_code(MissingNumber "src/patterns/binary/MissingNumber.cpp")

add_code(MaximumSubarray "src/patterns/dp/MaximumSubarray.cpp")
add_code(CoinChange "src/patterns/dp/CoinChange.cpp")
add_code(ClimbingStairs "src/patterns/dp/ClimbingStairs.cpp")
add_code(PartitionEqualSubsetSum "src/patterns/dp/PartitionEqualSubsetSum.cpp")
add_code(UniquePaths "src/patterns/dp/UniquePaths.cpp")
add_code(HouseRobber "src/patterns/dp/HouseRobber.cpp")
add_code(MaximumProductSubarray "src/patterns/dp/MaximumProductSubarray.cpp")
add_code(LongestIncreasingSubsequence "src/patterns/dp/LongestIncreasingSubsequence.cpp")
add_code(JumpGame "src/patterns/dp/JumpGame.cpp")
add_code(MaximalSquare "src/patterns/dp/MaximalSquare.cpp")
add_code(DecodeWays "src/patterns/dp/DecodeWays.cpp")
add_code(CombinationSumIV "src/patterns/dp/CombinationSumIV.cpp")

add_code(RansomNote "src/patterns/hash/RansomNote.cpp")
add_code(InsertDeleteGetRandom "src/patterns/hash/InsertDeleteGetRandom.cpp")

# STRINGS
add_code(ValidPalindrome "src/patterns/string/ValidPalindrome.cpp")
add_code(ValidAnagram "src/patterns/string/ValidAnagram.cpp")
add_code(LongestSubtring "src/patterns/string/LongestSubtring.cpp")
add_code(LongestPalindrome "src/patterns/string/LongestPalindrome.cpp")
add_code(StringToInteger "src/patterns/string/StringToInteger.cpp")
add_code(LongestPalindromicSubstring "src/patterns/string/LongestPalindromicSubstring.cpp")
add_code(FindAnagrams "src/patterns/string/FindAnagrams.cpp")
add_code(GroupAnagrams "src/patterns/string/GroupAnagrams.cpp")
add_code(CharacterReplacement "src/patterns/string/CharacterReplacement.cpp")
add_code(LargestNumber "src/patterns/string/LargestNumber.cpp")
#add_code(EncodeDecodeString "src/patterns/string/EncodeDecodeString.cpp")
add_code(LongestCommonPrefix "src/patterns/string/LongestCommonPrefix.cpp")

add_code(TwoSum "src/patterns/array/TwoSum.cpp")
add_code(BuySellStocks "src/patterns/array/BuySellStocks.cpp")
add_code(MajorityElement "src/patterns/array/MajorityElement.cpp")
add_code(ContainsDuplicate "src/patterns/array/ContainsDuplicate.cpp")
add_code(MeetingRooms "src/patterns/array/MeetingRooms.cpp")
add_code(MoveZeros "src/patterns/array/MoveZeros.cpp")
add_code(SortedSquares "src/patterns/array/SortedSquares.cpp")
add_code(InsertInterval "src/patterns/array/InsertInterval.cpp")

add_code(RotateArray "src/patterns/array/RotateArray.cpp")



add_code(InvertBinaryTree "src/patterns/tree/InvertBinaryTree.cpp")
add_code(BalancedBinaryTree "src/patterns/tree/BalancedBinaryTree.cpp")
add_code(DiameterBinaryTree "src/patterns/tree/DiameterBinaryTree.cpp")

add_code(RomanToInteger "src/patterns/math/RomanToInteger.cpp")
add_code(PalindromeNumber "src/patterns/math/PalindromeNumber.cpp")
add_code(RandomPickWeight "src/patterns/math/RandomPickWeight.cpp")
add_code(ReverseInteger "src/patterns/math/ReverseInteger.cpp")
add_code(Pow "src/patterns/math/Pow.cpp")

add_code(HitCounter "src/patterns/queue/HitCounter.cpp")

add_code(SpiralMatrix "src/patterns/matrix/SpiralMatrix.cpp")

add_code(RotateImage "src/patterns/matrix/RotateImage.cpp")
add_code(SetMatrixZeroes "src/patterns/matrix/SetMatrixZeroes.cpp")

#Lists
add_code(MergeTwoSortedLists "src/patterns/list/MergeTwoSortedLists.cpp")
add_code(LinkedListCycle "src/patterns/list/LinkedListCycle.cpp")
add_code(ReverseLinkedList "src/patterns/list/ReverseLinkedList.cpp")
add_code(MiddleLinkedList "src/patterns/list/MiddleLinkedList.cpp")
add_code(LRUCache "src/patterns/list/LRUCache.cpp")
add_code(RemoveNthEndList "src/patterns/list/RemoveNthEndList.cpp")
add_code(SwapAlternateNodes "src/patterns/list/SwapAlternateNodes.cpp")
add_code(OddEvenLinkedList "src/patterns/list/OddEvenLinkedList.cpp")
add_code(AddTwoNumbersList "src/patterns/list/AddTwoNumbersList.cpp")
add_code(SortLinkedList "src/patterns/list/SortLinkedList.cpp")
add_code(PalindromeLinkedList "src/patterns/list/PalindromeLinkedList.cpp")
add_code(ReorderList "src/patterns/list/ReorderList.cpp")
add_code(RotateRightList "src/patterns/list/RotateRightList.cpp")
