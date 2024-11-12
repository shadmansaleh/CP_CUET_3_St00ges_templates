#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//oset<int>s;
//*s.find_by_order(x) //(x-1)th largest element;
//s.order_of_key(x) //num of elements strictly less than x
