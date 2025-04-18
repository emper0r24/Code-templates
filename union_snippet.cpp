int vis[100005];

int union_arr(int a[], int b[], int c[], int n1, int n2){
    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(a[i] <= b[j]){
            if(!vis[a[i]]){
                c[k++] = a[i];
                vis[a[i]] = 1;
            }
            i++;
        }
        else{
            if(!vis[b[j]]){
                c[k++] = b[j];
                vis[b[j]] = 1;
            }
            j++;
        }
    }
    while(i < n1){
        if(!vis[a[i]]){
            c[k++] = a[i];
            vis[a[i]] = 1;
        }
        i++;
    }
    while(j < n2){
        if(!vis[b[j]]){
            c[k++] = b[j];
            vis[b[j]] = 1;
        }
        j++;
    }
    return k;
}