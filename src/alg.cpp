int cbinsearch(int* arr, int size, int value){
int left = 0;
int right = size - 1;

while (left <= right) {
  int middle = (left + right) / 2;
   if (arr[middle] == value) {
    return middle;
}
else if (arr[middle] < value)
 left = middle + 1;
else if (arr[middle] > value)
 right = middle - 1;
  }
return -1;
}

int countPairs1(int* arr, int len, int value){
int count = 0;
 for (int a = 0; a < len; a++) {
  for (int b = len - 1; b > 0; b--){
   if ( (arr[a] + arr[b] == value) && (arr[a]!=arr[b]) && (a != b))
    count++;
    }
  }
 return count/2;
}

int countPairs2(int* arr, int len, int value){
 int count = 0;
 int begin = 0;
 int end = len - 1;
  while (begin < end) {
   int result = arr[begin] + arr[end];
   if (result == value) {
  count++;
 begin++;
end--;
}
else {
 if (result < value) begin++;
else end--;
  }
 }
 return count;
}

int countPairs3(int* arr, int len, int value){
 int key = 0, count = 0;
  for (int z = 0; z < len; z++) {
   key = value;
   key = key - arr[z];
   int x = cbinsearch(arr, len, key);
  if (x >= 0 && x > z)
 count++;
 if (x < 0)
 continue;
 }
return count;
}
