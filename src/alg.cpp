// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) count++;
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = len - 1; j > i; j--) {
      if (arr[i] + arr[j] == value) count++;
      if (arr[i] + arr[j] < value) break;
    }
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int end = len - 1;
  for (int i = 0; i < len - 1; i++) {
    bool result = false;
    int start = i+1;
    int mid = (start + end) / 2;
    while (start <= end) {
      if (arr[mid] == value - arr[i]) {
        count++;
        result = true;
        break;
      } else if (arr[mid] > value - arr[i]) {
        end = mid - 1;
      } else if (arr[mid] < value - arr[i]) {
        start = mid + 1;
      }
      mid = (start + end) / 2;
    }
    int temp1 = mid;
    int temp2 = mid;
    if (result == true) {
      while (arr[temp1-1] == arr[mid] && temp1-1 != i) {
        count++;
        temp1--;
      }
      while (arr[temp2+1] == arr[mid]) {
        count++;
        temp2++;
      }
    }
  }
  return count;
}
