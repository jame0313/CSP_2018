#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

string* split(const string& str, const string& delim){
    string* string_list = new string[10];
    int idx=0;
    char * token =strtok(const_cast<char*>(str.c_str()),delim.c_str());
    while(token!=NULL){
        string_list[idx]=token;
        token = strtok(NULL,delim.c_str());
        ++idx;
    }
    return string_list;
}

struct Item{
    string name;
    string age;
    string id;
    string subjects[10];
    Item * pnext=NULL;
};

struct Item* create_item(){
    Item* i_new = new Item;
    return i_new;
}

struct Item* find_end_of_list(struct Item* linked_list_first_item){
    Item* lst_item = linked_list_first_item;
    while(lst_item->pnext != NULL) lst_item = lst_item->pnext;
    return lst_item;
}
void insert_item(struct Item* prev_item, struct Item* item){
    prev_item->pnext = item;
    return;
}

int main(void){
    ifstream fin;
    fin.open("input.txt");
    string line;
    Item * linked_list=NULL;
    while(getline(fin,line)){
        Item* item_new = create_item();
        string* lst=split(line,":");
        string* subject_lst=split(lst[3],",");
        item_new->name = lst[0];
        item_new->age = lst[1];
        item_new->id = lst[2];
        for(int i=0;i<10;i++) item_new->subjects[i] = subject_lst[i];
        if(linked_list != NULL)insert_item(find_end_of_list(linked_list),item_new);
        else linked_list=item_new;
        delete[] lst;
        delete[] subject_lst;
    }
    Item * cnt_node = linked_list;
    while(cnt_node!=NULL){
        string idyear = cnt_node->id.substr(0,4);
        if(idyear=="2013"){
            cout << cnt_node->name << '(' << cnt_node->id << "): " << cnt_node->subjects[0];
            for(int i=1;i<10;i++){
                if(cnt_node->subjects[i]!="") cout << " & " << cnt_node->subjects[i];
            }
            cout << endl;
        }
        cnt_node = cnt_node->pnext;
    }
    Item* pre_node = linked_list;
    while(pre_node!=NULL){
        cnt_node=pre_node->pnext;
        delete pre_node;
        pre_node=cnt_node;
    }
}
