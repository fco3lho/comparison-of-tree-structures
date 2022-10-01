#include "includes.hpp"

string selectTextFile();
void execute_Binary_Tree(string f);
void execute_AVL_Tree(string f);
void execute_RB_Tree(string f);
void execute_umap(string f);

int main(){
	string textFile = selectTextFile();

	execute_Binary_Tree(textFile);
	execute_AVL_Tree(textFile);
	execute_RB_Tree(textFile);
	execute_umap(textFile);

	return 0;
}

string selectTextFile(){
	string file1 = "text_files/randomNumbers_500.txt";
	string file2 = "text_files/randomNumbers_5000.txt";
	string file3 = "text_files/randomNumbers_50000.txt";
	string file4 = "text_files/randomNumbers_500000.txt";

	int option = -1, cancel = -1;

	cout << endl << "Para selecionar o arquivo com 500 números aleatórios, digite 1." << endl;
	cout << "Para selecionar o arquivo com 5000 números aleatórios, digite 2." << endl;
	cout << "Para selecionar o arquivo com 50000 números aleatórios, digite 3." << endl;
	cout << "Para selecionar o arquivo com 500000 números aleatórios, digite 4." << endl << endl;

	while(cancel != 0){
		cout << "Opção: ";
		cin >> option;

		if(option == 1){
			cancel = 0;
			return file1;
		}
		else if(option == 2){
			cancel = 0;
			return file2;
		}
		else if(option == 3){
			cancel = 0;
			return file3;
		}
		else if(option == 4){
			cancel = 0;
			return file4;
		}
		else{
			cout << "Opção inválida, digite novamente." << endl;
		}
	}

	return file1;
}

void execute_Binary_Tree(string f){
	binary_Tree *raiz = CreateTree_binary();
	Record_binary_tree r;
	insertElements_binary_tree(&raiz, r, f);
	searchAndRemoveElements_binary_tree(&raiz, r);
}

void execute_AVL_Tree(string f){
	avl_Tree *raiz = CreateTree_avl();
	Record_avl_tree r;
	insertElements_avl_tree(&raiz, r, f);
	searchAndRemoveElements_avl_tree(&raiz, r);	
}

void execute_RB_Tree(string f){
	Tree_rb *raiz = CreateTree_rb();
	Record_rb r;
	insertElements_rb(&raiz, r, f);
}

void execute_umap(string f){
	unordered_map <float, float> u_map;

	insertElements_umap(u_map, f);
	searchElements_umap(u_map);
}