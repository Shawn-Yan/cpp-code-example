/********************************************************************
1.Bubble sort
2.Select sort
3.Insert sort
4.quick sort
5.heap sort
6.merge sort

@author Shawn Yan
********************************************************************/

#include <iostream>

void Bubble_sort(int* s,int len){
	std::cout << "Bubble Sort" << std::endl;
	int temp;
	for(int i = 0 ; i < len - 1; i++){
		for(int j = 0; j < len - i - 1; j++){
			if(s[j] > s[j+1]){
				temp = s[j];
				s[j] = s[j+1];
				s[j+1] = temp;
			}
		}
	}
}

void Select_sort(int* s, int len){
	std::cout << "Select Sort" << std::endl;
	int i,j,k;
	int temp;
	for(i = 0; i < len -1; i++){
		k = 0;
		for(j = 1; j < len -i; j++){
			if(s[j] > s[k])
				k = j;	
		}
		temp = s[k];
		s[k] = s[len-1-i];
		s[len-1-i] = temp;
	}
}

void Insert_sort(int* s, int len){
	std::cout << "Insert Sort" << std::endl;
	int temp;
	for(int i = 0; i < len - 1; i++){
		for(int j = i + 1; j > 0; j--){
			if(s[j-1] > s[j]){
				temp = s[j-1];
				s[j-1] = s[j];
				s[j] = temp;
			}else
				break;
					
		}
	}
}

/*************************q_sort start**************************/
void Quick_sort_recursive(int* s,int len,int left,int right){
	if(left >= right)
		return ;
	int point = right;
	int i = left - 1;
	int j = left;
	int temp;
        for(;j < right;j++){
		if(s[j] < s[point]){
			i++;
			temp = s[j];
			s[j] = s[i];
			s[i] = temp;	
		}
	}
	int middle = i + 1;
	temp = s[middle];
	s[middle] = s[point];
	s[point] = temp;

	Quick_sort_recursive(s,len,left,middle - 1);
	Quick_sort_recursive(s,len,middle + 1,right);
}

void Quick_sort(int* s, int len){
	std::cout << "Quick Sort" << std::endl;
	Quick_sort_recursive(s,len,0,len - 1);
}
/*******************q_sort end************************/


/********************heap sort************************/
void max_heap(int* s,int i,int size){
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int largest = i;
	int temp;
	if(l <= size && s[l] > s[largest])
		largest = l;
	if(r <= size && s[r] > s[largest])
		largest =  r;
	if(i != largest){
		temp = s[i];
		s[i] = s[largest];
		s[largest] = temp;
		max_heap(s,largest,size);
	}
}

void build_max_heap(int*s,int len){
	for(int i = len/2;i >= 0;i--){
		max_heap(s,i,len-1);
	}
}

void Heap_sort(int* s, int len){
	std::cout << "Heap Sort" << std::endl;
	build_max_heap(s,len);
	int temp;
	for(int i = len-1;i > 0;i--){
		temp = s[i];
		s[i] = s[0];
		s[0] = temp;
		max_heap(s,0,i-1);
	}
}
/*******************heap sort end********************/
#define INF 1 << 16
#define max_size 100
int l_array[max_size];
int r_array[max_size];

/********************merge sort**********************/
void merge(int* s,int p,int q,int r){
	int l_len = r - p + 1;
	int r_len = q - r;
	std::cout << l_len << " " << r_len << std::endl;
	int i,j;
	for(i = 0; i < l_len; i++){
		l_array[i] = s[i + p];
	}	
	l_array[l_len] = INF;
	for(j = 0; j < r_len; j++){
		r_array[j] = s[j + r + 1];
	}
	r_array[r_len] = INF;
	i = 0;
	j = 0;
	for(int k = p; k <= q; k++){
		if(l_array[i] <= r_array[j]){
			s[k] = l_array[i];
			i++;
		}else{
			s[k] = r_array[j];
			j++;
		}
	}
}

void merge_recursive(int* s,int p,int q){
	if(p < q){
		int r = (p + q)/2; 
		merge_recursive(s,p,r);
		merge_recursive(s,r+1,q);
		merge(s,p,q,r);
	}
}
void Merge_sort(int* s, int len){
	std::cout << "Merge Sort" << std::endl;
	merge_recursive(s,0,len - 1);
}
/*******************merge sort end*******************/

int main(){
	int a[10] = {4,3,2,6,3,4,8,1,9,0};
	int len = 10;
	int input;
    while(true){
        std::cout << "Please input num:" << std::endl;
        std::cout << "1 for Bubble sort " << std::endl;
        std::cout << "2 for Select sort " << std::endl;
        std::cout << "3 for Insert sort " << std::endl;
        std::cout << "4 for quick sort " << std::endl;
        std::cout << "5 for heap sort  " << std::endl;
        std::cout << "6 for merge sort " << std::endl;
        std::cin >> input;
        while(input > 6 || input <= 0){
            std::cout << "Please try again" << std::endl;
            std::cin >> input;
        }
        time_t start = time(NULL);
        switch(input){
            case 1:
            Bubble_sort(a,len);
            break;
            case 2:
            Select_sort(a,len);
            break;
            case 3: 
            Insert_sort(a,len);
            break;
            case 4: 
            Quick_sort(a,len);
            break;
            case 5:
            Heap_sort(a,len);
            break;
            case 6:
            Merge_sort(a,len);
            break;
        }
        time_t stop = time(NULL);
        for(int i = 0; i < len; i++)
        std::cout << a[i] << " ";
        std::cout << std::endl << std::endl;
    }
	return 0;
}
