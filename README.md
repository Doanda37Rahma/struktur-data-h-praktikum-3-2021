# struktur-data-h-praktikum-3-2021

## Kata-kata
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/kk_bukti.png)
### Penjelasan Soal
Diberikan `n` kata yang disimpan [a-z]. Untuk setiap `q`, cari apakah kata tersimpan (output `1`) atau tidak (output`0`).
### Penjelasan Solusi
Program menggunakan [implementasi ADT Trie](https://github.com/Doanda37Rahma/struktur-data-h-asistensi-3-2021#implementasi-dalam-c), sebuah tree yang menyimpan data string. Sebuah node memiliki bool yang menandakan akhir kata, dan pointer ke huruf selanjutnya.
Program menggunakan [fungsi insert()](https://github.com/Doanda37Rahma/struktur-data-h-asistensi-3-2021#fungsi-insert) untuk memasukkan kata. Kemudian, program mencari kata dengan [fungsi search()](https://github.com/Doanda37Rahma/struktur-data-h-asistensi-3-2021#fungsi-search). `search()` hanya mengembalikan `1` jika saat menelusuri cabang trie tidak menemukan null dan huruf terakhir adalah leaf(ditandai bool).
### Visualisasi Solusi
Sample Input:
```
3
soalnya
mudah
dipahami
3
dan
soalnya
singkat
```
Sample Output:
```
0
1
0
```
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/kk_visual.png)


## MALUR NGULI
### Verdict
AC saat Revisi
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/mn_bukti.png)
### Penjelasan Soal
### Penjelasan Solusi
### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/mn_visual.png)

## Cayo Niat
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/cn_bukti.png)
### Penjelasan Soal
### Penjelasan Solusi
### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/cn_visual.png)


## Part Time
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/pt_bukti.png)
### Penjelasan Soal
Diberikan data indeks `m` barang (`p`) dan harganya (`q`), serta `n` query transaksi berisi jumlah pembelian (`x`) dan id (`y`). Program diminta mengeluarkan total pendapatan, `Maaf barang tidak tersedia` jika barang tidak ditemukan, dan jika input id tidak urut keluarkan `ID harus urut` dan akhiri program.
### Penjelasan Solusi
```
int main() {
	
	int num[MAX];
	int m,n,p,q,x,y;
	int sum=0;
	scanf("%d %d", &m,&n);
	int i;
	for(i=0; i<m; i++) {
		scanf("%d %d", &p,&q);
		if (p != i+1) {
			printf("ID harus urut\n");
			return 0;
		}
		num[p] = q;
	}
	
	for(i=0; i<n; i++) {
		scanf("%d %d", &x,&y);
		if (y<1 || y>m) {
			printf("Maaf barang tidak tersedia\n");
			continue;
		}
		sum += x * num[y];
	}
	
	printf("%d\n", sum);
    return 0;
}
```
Program menyimpan data barang menggunakan array. Pertama, program menyimpan `m` dan `n`, kemudian menyimpan data
### Visualisasi Solusi
Sample Input 0
```
10 7
1 65000
2 13700
4 37800
```
Sample Output 0
```
ID harus urut
```
Jika input id tidak urut dari input sebelumnya, keluarkan
Sample Input 1
```
5 5
1 13000
2 5500
3 8750
4 21900
5 30000
4 4
2 3
2 1
1 7
3 2
```
Sample Output 1
```
Maaf barang tidak tersedia
147600
```

![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/pt_visual.png)

## Bucyn
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/b_bukti.png)
### Penjelasan Soal
Ter
### Penjelasan Solusi
### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/b_visual.png)

## Nadut Belajar
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/nb_bukti.png)
### Penjelasan Soal
Program diminta menghitung selisih parent node dengan siblingnya
### Penjelasan Solusi
```
int main(int argc, char const *argv[])
{
    AVL avl;
    avl.init();
    
	int Q,T,n,t;
	cin >> Q >> T;
	for (int i=0; i<Q; i++) {
		cin >> n;
		avl.insert(n);
	}
	for (int i=0; i<T; i++) {
		cin >> t;
		cout << avl.parentSiblingDiff(t) << endl;
	}
	
    return 0;
}
```
Program menggunakan ADT AVL tree dengan parrent.
#### Fungsi `parentSiblingDiff()`
Berikut fungsi `parentSiblingDiff()` dan penjelasannya
```
    int parentSiblingDiff(int value) {
        
        AVLNode *temp = _search(_root, value);
        if (temp!=NULL) {
            if (temp->parent) { // jika node punnya parent, jika tidak(node=root) keluar 0
                if (temp->parent->parent) {  // jika parent node juga punya parent, jika tidak maka keluarkan nilai node itu
                    if (temp->parent->parent->left && temp->parent->parent->right) {  // jika parent node memiliki sibling, hitung perbedaan mutlak
                        int l=temp->parent->parent->left->data;
                        int r=temp->parent->parent->right->data;
                        return (l < r) ? r-l : l-r; 
                    } else {
                        return temp->parent->data;
                    }
                } else {
                    return temp->parent->data;
                }
            }
            return 0;
        }
        return 0;
}
```
### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/nb_visual.png)


