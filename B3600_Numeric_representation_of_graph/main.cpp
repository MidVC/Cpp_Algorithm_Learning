#include <bits/stdc++.h>


// Helper function that checks whether the graph have any self-loop.
// Returns true if there is self-loop, false otherwise
bool check_self_loop(const int *matrix, int n) {
    for(int i = 0; i < n; i++) {
        if (*(matrix + i*n + i)) return true;
    }
    return false;
}

int main() {
    int n, m, directed_graph, weighted_graph;
    bool replicated_input = false;
    scanf("%d%d%d%d", &n, &m, &directed_graph, &weighted_graph);

    // Declaration of the correlation matrix
    int correlation_matrix[n][n];
    int incidence_matrix[n][m];
    std::vector<int> adj_list[301];
    std::vector<std::pair<int, int>> adj_list_weighted[301];
    std::vector<int> A_backward[301];
    std::vector<std::pair<int, int>> BZ_backward[301];
    memset(correlation_matrix,0,sizeof(correlation_matrix));
    memset(incidence_matrix,0,sizeof(incidence_matrix));

    // Read the correlations
    for (int i = 0; i < m; i++) {

        // Read the two points and represent these as n1 and n2
        int n1, n2, weight=1;
        scanf("%d%d", &n1, &n2);

        // If the graph is weighted, then read the weight
        if (weighted_graph)  scanf("%d", &weight);

        // If the input is replicated, change replicated_input to true so that the later code would know
        //   that the adjacent matrix / weighted matrix would not need to be printed
        if (correlation_matrix[n1-1][n2-1])  replicated_input = true;

        // If the graph is directed, then only change the correlation n1 -> n2.
        //   Else change both n1 -> n2 and n2 -> n1
        if (directed_graph) {
            correlation_matrix[n1-1][n2-1] = weight;
            if (weighted_graph) {
                adj_list_weighted[n1].push_back(std::make_pair(n2, weight));
            }
            else {
                incidence_matrix[n1-1][i] = 1;
                incidence_matrix[n2-1][i] = -1;
                adj_list[n1].push_back(n2);
            }
            A_backward[n2].push_back(n1);
            BZ_backward[n2].push_back(std::make_pair(n1, weight));
        }
        else {
            correlation_matrix[n1-1][n2-1] = weight;
            correlation_matrix[n2-1][n1-1] = weight;
            if (weighted_graph) {
                adj_list_weighted[n1].push_back(std::make_pair(n2, weight));
                adj_list_weighted[n2].push_back(std::make_pair(n1, weight));
            }
            else {
                incidence_matrix[n1-1][i] = 1;
                incidence_matrix[n2-1][i] = 1;
                adj_list[n1].push_back(n2);
                adj_list[n2].push_back(n1);
            }
        }
    }

    // Output the adjacent matrix / weight matrix
    if (!replicated_input) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", correlation_matrix[i][j]);
                if (j != n-1)  printf(" ");
            }
            printf("\n");
        }
    }

    // Output the incidence matrix
    // If the graph is weighted or have self-loop, then there's no output
    if (!weighted_graph && !check_self_loop(*correlation_matrix, n)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%d", incidence_matrix[i][j]);
                if (j != m-1)  printf(" ");
            }
            printf("\n");
        }
    }

    // Output the adjacency list
    if (weighted_graph) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < adj_list_weighted[i].size(); j++) {
                printf("%d %d", adj_list_weighted[i][j].first, adj_list_weighted[i][j].second);
                if (j != adj_list_weighted[i].size()-1)  printf(" ");
            }
            if (adj_list_weighted[i].size())  printf("\n");
        }
    }
    else {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < adj_list[i].size(); j++) {
                printf("%d", adj_list[i][j]);
                if (j != adj_list[i].size()-1)  printf(" ");
            }
            if (adj_list[i].size())  printf("\n");
        }
    }

    // Output the forward table
    std::vector<int> A, B, Z;
    if (weighted_graph) {

        // Obtain the values of A, B, and Z.
        A.push_back(1);
        for(int i = 1; i <= n; i++) {
            A.push_back(A[i-1] + adj_list_weighted[i].size());
            for(int j = 0; j < adj_list_weighted[i].size(); j++) {
                B.push_back(adj_list_weighted[i][j].first);
                Z.push_back(adj_list_weighted[i][j].second);
            }
        }

        // Output A
        for(int i = 0; i < A.size(); i++) {
            printf("%d", A[i]);
            if (i != A.size()-1)  printf(" ");
        }
        printf("\n");

        // Output B
        for(int i = 0; i < B.size(); i++) {
            printf("%d", B[i]);
            if (i != B.size()-1)  printf(" ");
        }
        printf("\n");

        // Output Z
        for(int i = 0; i < Z.size(); i++) {
            printf("%d", Z[i]);
            if (i != Z.size()-1)  printf(" ");
        }
        printf("\n");
    }
    else {

        // Obtain the values of A, B, and Z.
        A.push_back(1);
        for(int i = 1; i <= n; i++) {
            A.push_back(A[i-1] + adj_list[i].size());
            for(int j = 0; j < adj_list[i].size(); j++) {
                B.push_back(adj_list[i][j]);
            }
        }

        // Output A
        for(int i = 0; i < A.size(); i++) {
            printf("%d", A[i]);
            if (i != A.size()-1)  printf(" ");
        }
        printf("\n");

        // Output B
        for(int i = 0; i < B.size(); i++) {
            printf("%d", B[i]);
            if (i != B.size()-1)  printf(" ");
        }
        printf("\n");

    }

    // Output the backward table
    if (directed_graph) {
        std::vector<int> A_back, B_back, Z_back;
        if (weighted_graph) {

            // Obtain A_back, B_back, Z_back
            A_back.push_back(1);
            for(int i = 1; i <= n; i++) {
                A_back.push_back(A_back[i-1] + A_backward[i].size());
                for(int j = 0; j < BZ_backward[i].size(); j++) {
                    B_back.push_back(BZ_backward[i][j].first);
                    Z_back.push_back(BZ_backward[i][j].second);
                }
            }

            // Output A_back
            for(int i = 0; i < A_back.size(); i++) {
                printf("%d", A_back[i]);
                if (i != A_back.size()-1)  printf(" ");
            }
            printf("\n");

            // Output B_back
            for(int i = 0; i < B_back.size(); i++) {
                printf("%d", B_back[i]);
                if (i != B_back.size()-1)  printf(" ");
            }
            printf("\n");

            // Output Z_back
            for(int i = 0; i < Z_back.size(); i++) {
                printf("%d", Z_back[i]);
                if (i != Z_back.size()-1)  printf(" ");
            }
            printf("\n");
        }
        else {

            // Obtain A_back, B_back
            A_back.push_back(1);
            for(int i = 1; i <= n; i++) {
                A_back.push_back(A_back[i-1] + A_backward[i].size());
                for(int j = 0; j < BZ_backward[i].size(); j++) {
                    B_back.push_back(BZ_backward[i][j].first);
                }
            }

            // Output A_back
            for(int i = 0; i < A_back.size(); i++) {
                printf("%d", A_back[i]);
                if (i != A_back.size()-1)  printf(" ");
            }
            printf("\n");

            // Output B_back
            for(int i = 0; i < B_back.size(); i++) {
                printf("%d", B_back[i]);
                if (i != B_back.size()-1)  printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
