/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"

using namespace std;


size_t PageTable::get_present_page_count() const {
    int current_page = 0;
    for( int i =0; i <rows.size(); i++){
        if (rows[i].present){
            current_page += 1;
        }
    }
    return current_page;
}


size_t PageTable::get_oldest_page() const {
    int oldest = rows.size()-1;
    for( int i =0; i <rows.size(); i++){
            if (rows[i].loaded_at < rows[oldest].loaded_at && rows[i].present){
                oldest = i;
            }
    }

    return oldest;
}


size_t PageTable::get_least_recently_used_page() const {
   int last_used = rows.size()-1;
    for( int i =0; i <rows.size(); i++){
             if (rows[i].last_accessed_at < rows[last_used].last_accessed_at && rows[i].present){
                last_used = i;
            }
    }

    return last_used;
}
