#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

// Structure to represent a node in the segment tree
struct Node {
    int max_val;
};

// Function to build the segment tree
void buildSegmentTree(const std::vector<int>& arr, std::vector<Node>& segment_tree, int node_idx, int start, int end) {
    if (start == end) {
        segment_tree[node_idx].max_val = arr[start];
        return;
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node_idx + 1;
    int right_child = 2 * node_idx + 2;

    buildSegmentTree(arr, segment_tree, left_child, start, mid);
    buildSegmentTree(arr, segment_tree, right_child, mid + 1, end);

    segment_tree[node_idx].max_val = std::max(segment_tree[left_child].max_val, segment_tree[right_child].max_val);
}

// Function to query the maximum value in a given range
int queryMax(const std::vector<Node>& segment_tree, int node_idx, int start, int end, int query_start, int query_end) {
    // If the current segment is completely outside the query range, return INT_MIN
    if (query_start > end || query_end < start) {
        return INT_MIN;
    }

    // If the current segment is completely inside the query range, return the maximum value in the segment
    if (query_start <= start && query_end >= end) {
        return segment_tree[node_idx].max_val;
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node_idx + 1;
    int right_child = 2 * node_idx + 2;

    int left_max = queryMax(segment_tree, left_child, start, mid, query_start, query_end);
    int right_max = queryMax(segment_tree, right_child, mid + 1, end, query_start, query_end);

    return std::max(left_max, right_max);
}

// Function to update the value of an element in the array and segment tree
void updateValue(std::vector<Node>& segment_tree, int node_idx, int start, int end, int arr_idx, int new_val) {
    // If the current segment does not contain the element, return
    if (arr_idx < start || arr_idx > end) {
        return;
    }

    // If the current segment contains the element and is a leaf node, update the value
    if (start == end) {
        segment_tree[node_idx].max_val = new_val;
        return;
    }

    int mid = start + (end - start) / 2;
    int left_child = 2 * node_idx + 1;
    int right_child = 2 * node_idx + 2;

    updateValue(segment_tree, left_child, start, mid, arr_idx, new_val);
    updateValue(segment_tree, right_child, mid + 1, end, arr_idx, new_val);

    segment_tree[node_idx].max_val = std::max(segment_tree[left_child].max_val, segment_tree[right_child].max_val);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Calculate the size of the segment tree
    int tree_size = 2 * pow(2, ceil(log2(n))) - 1;
    std::vector<Node> segment_tree(tree_size);

    // Build the segment tree
    buildSegmentTree(arr, segment_tree, 0, 0, n - 1);

    int m;
    std::cin >> m;

    while (m--) {
        std::string action;
        std::cin >> action;

        if (action == "get-max") {
            int query_start, query_end;
            std::cin >> query_start >> query_end;
            int max_val = queryMax(segment_tree, 0, 0, n - 1, query_start - 1, query_end - 1);
            std::cout << max_val << std::endl;
        } else if (action == "update") {
            int arr_idx, new_val;
            std::cin >> arr_idx >> new_val;
            updateValue(segment_tree, 0, 0, n - 1, arr_idx - 1, new_val);
        }
    }

    return 0;
}
// 6/10