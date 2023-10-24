void quickselect(int *v, int l, int r, int k){
    if(r <= l) return;

    int i = separa(v, l, r);

    if(i > k) quickselect(v, l, i - 1, k);
    if(i < k) quickselect(v, i + 1, r, k);
}