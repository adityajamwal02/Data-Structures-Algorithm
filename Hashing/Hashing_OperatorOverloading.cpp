
/// Syntax basically includes Typename T Operator Overloading dereferencing it
// Returning memory location by reference

 void insert_element(string key, float value)
    {
        int idx= hashfn(key);

        node<float>* n=new node<float>(key,value);
        n->next=table[idx];
        table[idx]=n;

        cs++;
    }

    int search(string key){
        int idx=hashfn(key);
        node<float> *temp=table[idx];
        while(temp!=NULL){
            if(temp->key == key){
                return &temp->value;
            }
        temp=temp->next;
        }
    return -1;
    }

T& operator[] (string key){
    T* valueFound=search(key);
    if(valueFound==NULL){
        T object;
        insert_element(key, object);
        valueFound=search(key);
    }
    return *valueFound;
}
