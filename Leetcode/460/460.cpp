
/*
Follow up: Could you do both operations in O(1) time complexity?
*/

class LFUCache {

	struct layer_t;
	struct entry_t;

	typedef struct layer_t layer;
	typedef struct entry_t entry;

	struct entry_t{
		entry* prev;
		entry* next;
        int key;
		int val;
		layer* player;
	};
	
	struct layer_t{
		int freq;
		entry* head;
		entry* tail;
		layer* prev;
		layer* next;
	};
	

	unordered_map<int, entry*> hash;
	layer* layers;
	int cap;
	int size;

	int touch(int key){
		int ret;

    	if(hash[key]){
    		entry* cur = hash[key];
    		ret = cur->val;
    		layer* player =  cur->player;

    		if (!cur->next) player->tail = cur->prev;

    		if (cur->prev) cur->prev->next = cur->next;
    		else player->head = cur->next;

    		if (!player->next){
    			cur->prev = cur->next = NULL;
    			layer* nlayer = (layer *) new layer();
    			*nlayer = {player->freq + 1 , cur, cur, player, NULL};
    			player->next = nlayer; 
    			cur->player = nlayer;
    		}
    		else{
    			layer* nlayer = player->next;
    			cur->prev = nlayer->tail;
    			cur->next = NULL;

    			if (nlayer->tail){
    				nlayer->tail->next = cur;
    			}
    			else{
    				nlayer->head = cur;
    			}
  				nlayer->tail = cur;
  				cur->player = nlayer;
    		}

    		if (!player->head){
    			if(player->prev) player->prev = player->next;    
    			else layers = player->next;			

    			delete player;
    		}
    	}
    	else{
    		ret = -1;
    	}
    	return ret;
	}

public:
    LFUCache(int capacity) {
        cap = capacity;
        size = 0;
        layers = NULL;
    }
    
    int get(int key) {
    	return touch(key);
    }
    
    void put(int key, int value) {
      	if (touch(key) == -1){
      		if (size == cap){
      			entry* rmv = layers->head;
      			layer* nlayer = layers->next;
      			layers->head = rmv->next;

      			if (!layers->head){
      				delete layers;
      				layers = nlayer;
      			}

     			hash.erase(rmv->key);
      			delete rmv;
      		}
      		else{
      			size++;
      		}

      		entry* nentry = new entry();
      		
      		if (layers){
      			if (layers->freq > 1){
      				layer* nlayer = layers;
      				layers = new layer();
      				*layers = {1, nentry, nentry, NULL, nlayer};
      				nlayer -> prev = layers;

      				*nentry = {NULL, NULL, key, value, layers};
      			}
      			else{
                    *nentry = {layers->tail, NULL, key, value, layers};
      				
      				layers->tail->next = nentry;
      				layers->tail = nentry;
      			}
      		}
      		else{
      			layers = new layer();
      			*layers = {1, nentry, nentry, NULL, NULL};
      			*nentry = {NULL, NULL, key, value, layers};
      		}

      		hash[key] = nentry;
      	}
      	else{
      		hash[key]->val = value;
      	}
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */