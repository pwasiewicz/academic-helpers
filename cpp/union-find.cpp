class UF {

private:
	int *labels, sets_count, *sz;

public:
	UF(int sets_no) {
		this->sets_count = sets_no;
		this->labels = new int[sets_no];
		this->sz = new int[sets_no];

		for (int i = 0; i < sets_no; i++) {
			this->labels[i] = i;
			this->sz[i] = 1;
		}
	}

	int find(int x) {
		int root = x;
		while (root != this->labels[root])
		{
			root = this->labels[root];
		}

		while (x != root) {
			int newp = this->labels[x];
			this->labels[x] = root;
			x = newp;
		}

		return root;
	}

	void merge(int x, int y) {
		int i = find(x);
		int j = find(y);
		if (i == j)
		{
			return;
		}

		if (sz[i] < sz[j])
		{
			this->labels[i] = j;
			sz[j] += sz[i];
		}
		else
		{
			this->labels[j] = i;
			sz[i] += sz[j];
		}

		this->sets_count--;
	}

	bool connected(int x, int y) {
		return this->find(x) == this->find(y);
	}

	int count() {
		return this->sets_count;
	}
};
