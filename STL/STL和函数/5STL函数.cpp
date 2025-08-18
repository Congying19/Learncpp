/*
	STL 算法库（由头文件 algorithm 和 numeric 支持）提供了大量基于迭代器的非成员模板函数。
	
	正如第 16 章介绍的，选择的模板参数名指出了特定参数应模拟的概念。
	例如，
	ForwardIterator 用于指出，参数至少应模拟正向迭代器的要求；
	Predicate(谓词) 用于指出，参数应是一个接受一个参数并返回 bool 值的函数对象。
	
	C++标准将算法分成 4 组：
	非修改式序列操作、
	修改式序列操作、
	排序和相关运算符
	数值操作（C++11 将数值操作从 STL 移到了 numeric 库中，但这不影响它们的用法）。
	
	序列操作（sequence operation）表明：函数将接受两个迭代器作为参数，它们定义了要操作的区间或序列。
	修改式（mutating）意味着函数可以修改容器的内容。
*/

/*
	（1）非修改型序列操作：
	和前面一样，迭代器对指出了区间，而选择的模板参数名指出了迭代器的类型。
	通常，[first, last]区间指的是从 first 到 last（不包括 last）。
	有些函数接受两个区间，这两个区间的容器类型可以不同。
	例如，可以使用 equal()来对链表和矢量进行比较。
	
	作为参数传递的函数是函数对象，这些函数对象可以是指针（如函数名），也可以是定义了()操作的对象。
	
	谓词是接受一个参数的布尔函数，二元谓词是接受2个参数的布尔函数
	（函数可以不是 bool 类型，只要它对于 false 返回 0，对于 true 返回非 0 值）。

————————————————————————————————————
	1. all_of() (C++11)
	template<class InputIterator, class Predicate>
	bool all_of(InputIterator first, InputIterator last,
		Predicate pred);

	如果对于区间[first, last]中的每个迭代器，pred(*i)都为 true，或者该区间为空，
	则函数 all_of() 返回 true；否则返回 false。

————————————————————————————————————
	2. any_of() (C++11)
	template<class InputIterator, class Predicate>
	bool any_of(InputIterator first, InputIterator last,
		Predicate pred);

	如果对于区间[first, last]中的每个迭代器，pred(*i)都为 false，或者该区间为空，
	则函数 any_of() 返回 false；否则返回 true。

————————————————————————————————————
	3. none_of() (C++11)
	template<class InputIterator, class Predicate>
	bool none_of(InputIterator first, InputIterator last,
		Predicate pred);

	如果对于区间[first, last]中的每个迭代器，pred(*i)都为 false，或者该区间为空，
	则函数 all_of() 返回 true；否则返回 false。

————————————————————————————————————

	4. for_each()
	template<class InputIterator, class Function>
	Function for_each(InputIterator first, InputIterator last,
		Function f);

	for_each()函数将函数对象 f 用于[first, last]区间中的每个元素，它也返回 f。

————————————————————————————————————

	5. find()
	template<class InputIterator, class T
	InputIterator find(InputIterator first, InputIterator last,
		Const T& value);

	find()函数返回一个迭代器，该迭代器指向区间[first, last]中第一个值为 value 的元素；
	如果没有找到这样的元素，则返回 last。

————————————————————————————————————
	6. find_if()
	template<class InputIterator, class Predicate>
	InputIterator find_if(InputIterator first, InputIterator last,
		Predicate pred);

	find_if()函数返回一个迭代器，该迭代器指向[first, last]区间中第一个
	对其调用函数对象 pred(*i)时结果为 true 的元素；如果没有找到这样的元素，则返回 last。

————————————————————————————————————
	7. find_if_not()
	template<class InputIterator, class Predicate>
	InputIterator find_if_not(InputIterator first, InputIterator last,
		Predicate pred);

	find_if_not()函数返回一个迭代器，该迭代器指向[first, last]区间中第一个
	对其调用函数对象 pred(*i)时结果为 false 的元素；如果没有找到这样的元素，则返回 last。

—————————————————————————————————————
	8. find_end()
	template<class ForwardIterator1, class ForwardIterator2>
	ForwardIterator1 find_end(
		ForwardIterator1 first1, ForwardIterator1 last1,
		FormardIterator2 first2, ForwardIterator2 last2);

	template<class ForwardIterator1, class ForwardIterator2,
		class BinaryPredicate>
	ForwardIterator1 find_end(
		ForwardIterator1 first1, ForwardIterator1 last1,
		ForwardIterator2 first2, ForwardIterator2 last2,
		BinaryPredicate pred);
	find_end()函数返回一个迭代器，该迭代器指向[first1, last1]区间中
	最后一个与[first2, last2]区间的内容匹配的序列的第一个元素。
	
	第一个版本使用值类型的==运算符来比较元素；
	第二个版本使用二元谓词函数对象pred来比较元素。
		也就是说，如果pred(*it1, *it2)为true，则it1和it2指向的元素匹配。
		如果没有找到这样的元素，则它们都返回last1。

——————————————————————————————————————
	9. find_first_of()
	template<class ForwardIterator1, class ForwardIterator2>
	ForwardIterator1 find_first_of(
		ForwardIterator1 first1, ForwardIterator1 last1,
		ForwardIterator2 first2, ForwardIterator2 last2);

	template<class ForwardIterator1, class ForwardIterator2,
		class BinaryPredicate>
	ForwardIterator1 find_first_of(
		ForwardIterator1 first1, ForwardIterator1 last1,
		ForwardIterator2 first2, ForwardIterator2 last2,
		BinaryPredicate pred);
	find_first_of()函数返回一个迭代器，该迭代器指向区间[first1, last1]中
	第一个与[first2, last2]区间中的任何元素匹配的元素。
	第一个版本使用值类型的==运算符对元素进行比较；
	第二个版本使用二元谓词函数对象pred来比较元素。
		也就是说，如果pred(*it1, *it2)为true，则it1和it2指向的元素匹配。
		如果没有找到这样的元素，则它们都将返回last1。

———————————————————————————————————————
	10. adjacent_find()
	template<class ForwardIterator>
	ForwardIterator adjacent_find(ForwardIterator first,
		ForwardIterator last);

	template<class ForwardIterator, class BinaryPredicate>
	ForwardIterator adjacent_find(ForwardIterator first,
		ForwardIterator last, BinaryPredicate pred);

	adjacent_find()函数返回一个迭代器，该迭代器指向[first1, last1]区间中
	第一个与其后面的元素匹配的元素。如果没有找到这样的元素，则返回last。
	第一个版本使用值类型的==运算符对元素进行比较；
	第二个版本使用二元谓词函数对象pred来比较元素。
		也就是说，如果pred(*it1, *it2)为true，则it1和it2指向的元素匹配。

————————————————————————————————————————
	11. count()
	template<class InputIterator, class T>
	  typename iterator_traits<InputIterator>::difference_type
		count(InputIterator first, InputIterator last, const T& value);

		count()函数返回[first, last]区间中与值value匹配的元素数目。
		对值进行比较时，将使用值类型的==运算符。
		返回值类型为整型，它足以存储容器所能存储的最大元素数。

————————————————————————————————————————
	12. count_if()
	template<class InputIterator, class Predicate>
		typename iterator traits<InputIterator>::difference type
			count_if(InputIterator first, InputIterator last, Predicate Pred);
	
		count_if()函数返回[first, last]区间中这样的元素数目，
		即将其作为参数传递给函数对象 pred 时，后者的返回值为 true。

————————————————————————————————————————
	13. mismatch()
	template<class InputIterator1, class InputIterator2>
		pair<InputIterator1, InputIterator2>
			mismatch(InputIterator1 first1,
					 InputIterator1 last1, InputIterator2 first2);

	template<class InputIterator1, class InputIterator2,
										class BinaryPredicate>
	pair<InputIterator1, InputIterator2>
		mismatch(InputIterator1 first1,
				 InputIterator1 last1, InputIterator2 first2,
				 BinaryPredicate pred);

	每个 mismatch()函数都在[first1, last1]区间中查找第一个与
	从 first2 开始的区间中相应元素不匹配的元素，并返回两个迭代器，它们指向不匹配的两个元素。
	如果没有发现不匹配的情况，则返回值为 pair<last1, first2 + (last1 - first1)>。
	
	第一个版本使用 == 运算符来测试匹配情况；
	第二个版本使用二元谓词函数对象 pred 来比较元素。
		也就是说，如果 pred(*it1, *it2)为 false，则 it1 和 it2 指向的元素不匹配。
——————————————————————————————————————————

	14. equal()
	template<class InputIterator1, class InputIterator2>
		bool equal(InputIterator1 first1, InputIterator1 last1,
										InputIterator2 first2);

	template<class InputIterator1, class InputIterator2,
								class BinaryPredicate>
	bool equal(InputIterator1 first1, InputIterator1 last1,
			InputIterator2 first2, BinaryPredicate pred);

	如果[first1, last1]区间中每个元素都与以 first2 开始的序列中相应元素匹配，
	则 equal()函数返回 true，否则返回 false。
	第一个版本使用值类型的 == 运算符来比较元素；
	第二个版本使用二元谓词函数对象 pred 来比较元素。
		也就是说，如果 pred(*it1, *it2)为 true，则 it1 和 it2 指向的元素匹配。

——————————————————————————————————————————
	15. is_permutation() (C++11)
	template<class InputIterator1, class InputIterator2>
	bool is_permutation(InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2);

	template<class InputIterator1, class InputIterator2,
		class BinaryPredicate>
	bool is_permutation(InputIterator1 first1, InputIterator1 last1,
							InputIterator2 first2, BinaryPredicate pred);

	如果通过对从 first2 开始的序列进行排列，可使其与区间[first1, last1]相应的元素匹配，
	则函数 is_permutation() 返回 true，否则返回 false。
	第一个版本使用值类型的 == 运算符来比较元素；
	第二个版本使用二元谓词函数对象 pred 来比较元素，
		也就是说，如果 pred(*it1, *it2)为 true，则 it1 和 it2 指向的元素匹配。

——————————————————————————————————————————

	16. search()
	template<class ForwardIterator1, class ForwardIterator2>
	ForwardIterator1 search(
		ForwardIterator1 first1, ForwardIterator1 last1,
		ForwardIterator2 first2, ForwardIterator2 last2);

	template<class ForwardIterator1, class ForwardIterator2,
									class BinaryPredicate>
	ForwardIterator1 search(
		ForwardIterator1 first1, ForwardIterator1 last1,
		ForwardIterator2 first2, ForwardIterator2 last2,
		BinaryPredicate pred);

	search()函数在[first1, last1]区间中搜索第一个与[first2, last2]区间中相应的序列匹配的序列；
	如果没有找到这样的序列，则返回 last1。
	第一个版本使用值类型的 == 运算符来对元素进行比较；
	第二个版本使用二元谓词函数对象 pred 来比较元素。
		也就是说，如果 pred(*it1, *it2)为 true，则 it1 和 it2 指向的元素是匹配的。

——————————————————————————————————————————

	17. search_n()
	template<class ForwardIterator, class Size, class T>
	ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
							Size count, const T& value);
	template<class ForwardIterator, class Size, class T, class BinaryPredicate>
	ForwardIterator search_n(ForwardIterator first, ForwardIterator last,
							Size count, const T& value, BinaryPredicate pred);

	search_n()函数在[first1, last1]区间中查找第一个与 count 个 value 组成的序列匹配的序列；
	如果没有找到这样的序列，则返回 last1。
	第一个版本使用值类型的 == 运算符来对元素进行比较；
	第二个版本使用二元谓词函数对象 pred 来比较元素。
		也就是说，如果 pred(*it1, *it2)为 true，则 it1 和 it2 指向的元素是匹配的。

*/
/*
	（2）修改式序列操作：
——————————————————————————————————————
	1. copy()
	template<class InputIterator, class OutputIterator>
	OutputIterator copy(InputIterator first, InputIterator last,
											OutputIterator result);

	copy()函数将[first, last]区间中的元素复制到区间[result, result + (last - first)]中，
	并返回 result + (last - first)，即指向被复制到的最后一个位置后面的迭代器。
	该函数要求 result 不位于[first, last]区间中，也就是说，目标不能与源重叠。

——————————————————————————————————————
	2. copy_n() (C++11)
	template<class InputIterator, class Size, class OutputIterator>
	OutputIterator copy_n(InputIterator first, Size n,
									OutputIterator result);

	函数 copy_n()从位置 first 开始复制 n 个元素到区间[result, result + n] 中，
	并返回 result + n，即指向被复制到的最后一个位置后面的迭代器。该函数不要求目标和源不重叠。

———————————————————————————————————————
	3. copy_if() (C++11)
	template<class InputIterator, class OutputIterator,
						class Predicate>
	OutputIterator copy_if(InputIterator first, InputIterator last,
						OutputIterator result, Predicate pred);

	函数 copy_if()将[first, last]区间中满足谓词 pred 的元素
	复制到区间[result, result + (last - first)]中，并返回 result + (last - first)，
	即指向被复制到的最后一个位置后面的迭代器。
	该函数要求 result 不位于[first, last]区间中，也就是说，目标不能与源重叠。

————————————————————————————————————————
	4. copy_backward()
	template<class BidirectionalIterator1,
		class BidirectionalIterator2>
	BidirectionalIterator2 copy_backward(BidirectionalIterator1 first,
		BidirectionalIterator1 last, BidirectionalIterator2 result);

	函数 copy_backward()将[first, last]区间中的元素复制到区间[result-(last-first), result]中。
	复制从 last-1 开始，该元素被复制到位置 result-1，然后由后向前处理，直到 first。
	该函数返回 result-(last-first)，即指向被复制到的最后一个位置后面的迭代器。
	该函数要求 result 不位于[first, last]区间中。
	然而，由于复制是从后向前进行的，因此目标和源可能重叠。

————————————————————————————————————————
	5. move() (C++11)
	template<class InputIterator, class OutputIterator>
	OutputIterator move(InputIterator first, InputIterator last,
		OutputIterator result);

	函数 move()使用 std::move() 将[first, last]区间中的元素移到区间[result, result+(last-first)]中，
	并返回 result+(last-first)，即指向被复制到的最后一个位置后面的迭代器。
	该函数要求 result 不位于[first, last]区间中，也就是说，目标不能与源重叠。

————————————————————————————————————————
	6. move_backward() (C++11)
	template<class BidirectionalIterator1,
		class BidirectionalIterator2>
	BidirectionalIterator2 move_backward(BidirectionalIterator1 first,
		BidirectionalIterator1 last, BidirectionalIterator2 result);

	函数 move_backward()使用 std::move() 将[first, last]区间中的元素
	移到区间[result-(last-first), result]中。复制从 last-1 开始，
	该元素被复制到位置 result-1，然后由后向前处理，直到 first。
	该函数返回 result-(last-first)，即指向被复制到的最后一个位置后面的迭代器。
	该函数要求 result 不位于[first, last]区间中。然而，由于复制是从后向前进行的，因此目标和源可能重叠。

—————————————————————————————————————————
	7. swap()
	template<class T> void swap(T& a, T& b);
	swap()函数对引用指定的两个位置中存储的值进行交换（C++11 将这个函数移到了头文件 utility 中）。

—————————————————————————————————————————
	8. swap_ranges()
	template<class ForwardIterator1, class ForwardIterator2>
	ForwardIterator2 swap_ranges(
		ForwardIterator1 first1, ForwardIterator1 last1,
		ForwardIterator2 first2);

	swap_ranges()函数将[first1, last1]区间中的值与从 first2 开始的区间中对应的值交换。
	这两个区间不能重叠。

——————————————————————————————————————————
	9. iter_swap()
	template<class ForwardIterator1, class ForwardIterator2>
	void iter_swap(ForwardIterator1 a, ForwardIterator2 b);

	iter_swap()函数将迭代器指定的两个位置中存储的值进行交换。

——————————————————————————————————————————
	10. transform()
	template<class InputIterator, class OutputIterator, class UnaryOperation>
	OutputIterator transform(InputIterator first, InputIterator last,
		OutputIterator result, UnaryOperation op);
	
	template<class InputIterator1, class InputIterator2, class OutputIterator,
		class BinaryOperation>
	OutputIterator transform(InputIterator1 first1, InputIterator1 last1,
		InputIterator2 first2, OutputIterator result,
		BinaryOperation binary_op);

	第一个版本的 transform() 将一元函数对象 op 应用到 [first, last] 区间中每个元素，
	并将返回值赋给从 result 开始的区间中对应的元素。
	因此，*result 被设置为 op(*first)，依此类推。
	该函数返回 result + (last - first)，即目标区间的超尾值。

	第二个版本的 transform() 将二元函数对象 op 应用到 [first1, last1] 区间
	和 [first2, last2] 区间中的每个元素，并将返回值赋给从 result 开始的区间中对应的元素。
	因此，*result 被设置成 op(*first1, *first2)，依此类推。
	该函数返回 result + (last - first)，即目标区间的超尾值。

———————————————————————————————————————————
	11. replace()
	template<class ForwardIterator, class T>
	void replace(ForwardIterator first, ForwardIterator last,
		const T& old_value, const T& new_value);
	
	replace() 函数将 [first, last] 中的所有 old_value 替换为 new_value。

———————————————————————————————————————————
	12. replace_if()
	template<class ForwardIterator, class Predicate, class T>
	void replace_if(ForwardIterator first, ForwardIterator last,
		Predicate pred, const T& new_value);
	replace_if() 函数使用 new_value 值替换 [first, last] 区间中 pred (old) 为 true 的每个 old 值。

———————————————————————————————————————————
	13. replace_copy()
	template<class InputIterator, class OutputIterator, class T>
	OutputIterator replace_copy(InputIterator first, InputIterator last,
		OutputIterator result, const T& old_value, const T& new_value);
	replace_copy() 函数将 [first, last] 区间中的元素复制到从 result 开始的区间中，
	但它使用 new_value 代替所有的 old_value。
	该函数返回 result + (last - first)，即目标区间的超尾值。

———————————————————————————————————————————
	14. replace_copy_if()
	template<class Iterator, class OutputIterator, class Predicate, class T>
	OutputIterator replace_copy_if(Iterator first, Iterator last,
		OutputIterator result, Predicate pred, const T& new_value);
	
	replace_copy_if() 函数将 [first, last] 区间中的元素复制到从 result 开始的区间中，
	但它使用 new_value 代替 pred(old) 为 true 的所有 old 值。
	该函数返回 result + (last - first)，即目标区间的超尾值。

———————————————————————————————————————————
	15. fill()
	template<class ForwardIterator, class T>
	void fill(ForwardIterator first, ForwardIterator last, const T& value);
	
	fill() 函数将 [first, last] 区间中的每个元素都设置为 value。

———————————————————————————————————————————
	16. fill_n()
	template<class OutputIterator, class Size, class T>
	void fill_n(OutputIterator first, Size n, const T& value);
	
	fill_n() 函数将从 first 位置开始的前 n 个元素都设置为 value。

———————————————————————————————————————————
	17. generate()
	template<class ForwardIterator, class Generator>
	void generate(ForwardIterator first, ForwardIterator last, Generator gen);

	generate() 函数将 [first, last] 区间中的每个元素都设置为 gen(), 其中 gen 是一个生成器函数对象，
	即不接受任何参数。例如，gen 可以是一个指向 rand()的指针。

———————————————————————————————————————————
	18. generate_n()
	template<class OutputIterator, class Size, class Generator>
	void generate_n(OutputIterator first, Size n, Generator gen);
	
	generate_n()函数将从 first 开始的区间中前 n 个元素都设置为 gen()，
	其中，gen 是一个生成器函数对象，即不接受任何参数。例如，gen 可以是一个指向 rand()的指针。

————————————————————————————————————————————
	19. remove()
	template<class ForwardIterator, class T>
	ForwardIterator remove(ForwardIterator first, ForwardIterator last,
		const T& value);

	remove()函数删除[first, last]区间中所有值为 value 的元素，并返回得到的区间的超尾迭代器。
	该函数是稳定的，这意味着未删除的元素的顺序将保持不变。

	注意：由于所有的 remove()和 unique()函数都不是成员函数，同时这些函数并非只能用于 STL 容器，
	因此它们不能重新设置容器的长度。相反，它们返回一个指示新超尾位置的迭代器。
	通常，被删除的元素只是被移到容器尾部。
	然而，对于 STL 容器，可以使用返回的迭代器和 erase()方法来重新设置 end()。

————————————————————————————————————————————
	20. remove_if()
	template<class ForwardIterator, class Predicate>
	ForwardIterator remove_if(ForwardIterator first, ForwardIterator last,
		Predicate pred);

	remove_if()函数将 pred(val)为 true 的所有 val 值从[first, last]区间删除，
	并返回得到的区间的超尾迭代器。该函数是稳定的，这意味着未删除的元素的顺序将保持不变。

—————————————————————————————————————————————
	21. remove_copy()
	template<class InputIterator, class OutputIterator, class T>
	OutputIterator remove_copy(InputIterator first, InputIterator last,
		OutputIterator result, const T& value);

	remove_copy()函数将[first, last]区间中的值复制到从 result 开始的区间中，
	复制时将忽略 value。该函数返回得到的区间的超尾迭代器。
	该函数是稳定的，这意味着没有被删除的元素的顺序将保持不变。

——————————————————————————————————————————————
	22. remove_copy_if()
	template<class InputIterator, class OutputIterator, class Predicate>
	OutputIterator remove_copy_if(InputIterator first, InputIterator last,
		OutputIterator result, Predicate pred);

	remove_copy_if()函数将[first, last]区间中的值复制到从 result 开始的区间，
	但复制时忽略 pred(val)为 true 的 val。该函数返回得到的区间的超尾迭代器。
	该函数是稳定的，这意味着没有删除的元素的顺序将保持不变。

——————————————————————————————————————————————
	23. unique()
	template<class ForwardIterator>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last);

	template<class ForwardIterator, class BinaryPredicate>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last,
		BinaryPredicate pred);

	unique()函数将[first, last]区间中由两个或更多相同元素构成的序列压缩为一个元素，
	并返回新区间的超尾迭代器。
	第一个版本使用值类型的 == 运算符对元素进行比较；
	第二个版本使用二元谓词函数对象 pred 来比较元素。
		也就是说，如果 pred(*it1, *it2)为 true，则 it1 和 it2 指向的元素是匹配的。

——————————————————————————————————————————————
	24. unique_copy()
	template<class InputIterator, class OutputIterator>
	OutputIterator unique_copy(InputIterator first, InputIterator last,
		OutputIterator result);

	template<class InputIterator, class OutputIterator, class BinaryPredicate>
	OutputIterator unique_copy(InputIterator first, InputIterator last,
		OutputIterator result, BinaryPredicate pred);

	unique_copy()函数将[first, last]区间中的元素复制到从result开始的区间中，
	并将由两个或更多个相同元素组成的序列压缩为一个元素。该函数返回新区间的超尾迭代器。
	第一个版本使用值类型的==运算符，对元素进行比较；
	第二个版本使用二元谓词函数对象pred来比较元素。
		也就是说，如果pred(*it1, *it2)为true，则it1和it2指向的元素是匹配的。

——————————————————————————————————————————————
	25. reverse()
	template<class BidirectionalIterator>
	void reverse(BidirectionalIterator first, BidirectionalIterator last);
	reverse()函数通过调用swap(first, last - 1)等来反转[first, last]区间中的元素。

——————————————————————————————————————————————
	26. reverse_copy()
	template<class BidirectionalIterator, class OutputIterator>
	OutputIterator reverse_copy(BidirectionalIterator first,
		BidirectionalIterator last,
		OutputIterator result);

	reverse_copy()函数按相反的顺序将[first, last]区间中的元素复制到从result开始的区间中。
	这两个区间不能重叠。

——————————————————————————————————————————————
	27. rotate()
	template<class ForwardIterator>
	void rotate(ForwardIterator first, ForwardIterator middle,
		ForwardIterator last);

	rotate()函数将[first, last]区间中的元素左旋。
	middle处的元素被移到first处，middle + 1处的元素被移到first + 1处，依此类推。
	middle前的元素绕回到容器尾部，以便first处的元素可以紧接着last - 1处的元素。

———————————————————————————————————————————————
	28. rotate_copy()
	template<class ForwardIterator, class OutputIterator>
	OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle,
		ForwardIterator last, OutputIterator result);

	rotate_copy()函数使用为rotate()函数描述的旋转序列，
	将[first, last]区间中的元素复制到从result开始的区间中。

——————————————————————————————————————————————
	29. random_shuffle()
	template<class RandomAccessIterator>
	void random_shuffle(RandomAccessIterator first, RandomAccessIterator last);

	这个版本的random_shuffle()函数将[first, last]区间中的元素打乱。
	分布是一致的，即原始顺序的每种可能排列方式出现的概率相同。

————————————————————————————————————————————————
	30. random_shuffle()
	template<class RandomAccessIterator, class RandomNumberGenerator>
	void random_shuffle(RandomAccessIterator first, RandomAccessIterator last,
		RandomNumberGenerator&& random);
	这个版本的 random_shuffle()函数将[first, last]区间中的元素打乱。
	函数对象 random 确定分布。
	假设有 n 个元素，表达式 random(n)将返回[0,n]区间中的一个值。
	在 C++98 中，参数 random 是一个左值引用，而在 C++11 中是一个右值引用。

——————————————————————————————————————————————

	31. shuffle()
	template<class RandomAccessIterator, class UniformRandomNumberGenerator>
	void shuffle(RandomAccessIterator first, RandomAccessIterator last,
		UniformRandomNumberGenerator&& rgen);

	函数 shuffle()将[first, last]区间中的元素打乱。
	函数对象 rgen 确定分布，它应满足 C++11 指定的有关均匀随机数生成器的要求。
	假设有 n 个元素，表达式 rgen(n)将返回[0,n]区间中的一个值。

——————————————————————————————————————————————
	32. is_partitioned() (C++11)
	template<class InputIterator, class Predicate>
	bool is_partitioned(InputIterator first,
		InputIterator last, Predicate pred);

	如果区间为空或根据 pred 进行了分区（即满足谓词 pred 的元素都在不满足该谓词的元素前面），
	函数 is_partitioned()将返回 true，否则返回 false。

——————————————————————————————————————————————
	33. partition()
	template<class BidirectionalIterator, class Predicate>
	BidirectionalIterator partition(BidirectionalIterator first,
		BidirectionalIterator last,
		Predicate pred);

	函数 partition()将其值 val 使得 pred(val)为 true 的元素都放在不满足该测试条件的所有元素之前。
	这个函数返回一个迭代器，指向最后一个使得谓词对象函数为 true 的值的后面。

——————————————————————————————————————————————
	34. stable_partition()
	template<class BidirectionalIterator, class Predicate>
	BidirectionalIterator stable_partition(BidirectionalIterator first,
		BidirectionalIterator last,
		Predicate pred);

	函数 stable_partition()将其值 val 使得 pred(val)为 true 的元素都放在
	不满足该测试条件的所有元素之前；在这两组中，元素的相对顺序保持不变。
	这个函数返回一个迭代器，指向最后一个使得谓词对象函数为 true 的值的后面。

——————————————————————————————————————————————
	35. partition_copy() (C++11)
	template<class InputIterator, class OutputIterator1,
		class OutputIterator2, class Predicate>
	pair<OutputIterator1, OutputIterator2> partition_copy(
		InputIterator first, InputIterator last,
		OutputIterator1 out_true, OutputIterator2 out_false,
		Predicate pred);

	函数 partition_copy()将所有这样的元素都复制到从 out_true 开始的区间中，
	即其值 val 使得 pred(val)为 true；并将其他的元素都复制到从 out_false 开始的区间中。
	它返回一个 pair 对象，该对象包含两个迭代器，分别指向从 out_true 和 out_false 开始的区间的末尾。

——————————————————————————————————————————————
	36. partition_point() (C++11)
	template<class ForwardIterator, class Predicate>
	ForwardIterator partition_point(ForwardIterator first,
		ForwardIterator last,
		Predicate pred);
*/