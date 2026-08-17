int find_max_ok(int a[], int L, int R)
{
    int l = L;
    int r = R;

    int ans = -1;   // 没有满足条件的数

    while (l <= r) {
        int mid = l + (r - l) >> 1;

        if (check(a[mid])) {
            ans = a[mid];      // 当前满足条件
            l = mid + 1;       // 尝试找更大的
        }
        else {
            r = mid - 1;
        }
    }

    return ans;
}