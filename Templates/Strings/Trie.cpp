#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class Trie {
private:
    struct Nodo {
        map<char, unique_ptr<Nodo>> hijos;
        bool esFin = false;
        int contador = 0;
    };

    unique_ptr<Nodo> raiz;

    const Nodo* recorrer(const string& texto) const {
        const Nodo* nodo = raiz.get();
        for (char c : texto) {
            auto it = nodo->hijos.find(c);
            if (it == nodo->hijos.end()) return nullptr;
            nodo = it->second.get();
        }
        return nodo;
    }

    void dfs(Nodo* nodo) {
        ++nodo->contador;
        for (auto& [c, hijo] : nodo->hijos)
            dfs(hijo.get());
    }

    void mostrarContadores(const Nodo* nodo, string& actual) const {
        cout << (actual.empty() ? "(raiz)" : actual)
             << " -> " << nodo->contador << '\n';
        for (const auto& [c, hijo] : nodo->hijos) {
            actual.push_back(c);
            mostrarContadores(hijo.get(), actual);
            actual.pop_back();
        }
    }

    bool eliminarRec(Nodo* nodo, const string& palabra, size_t i) {
        if (i == palabra.size()) {
            if (!nodo->esFin) return false;
            nodo->esFin = false;
            return nodo->hijos.empty();
        }
        auto it = nodo->hijos.find(palabra[i]);
        if (it == nodo->hijos.end()) return false;
        if (eliminarRec(it->second.get(), palabra, i + 1)) {
            nodo->hijos.erase(it);
            return nodo->hijos.empty() && !nodo->esFin;
        }
        return false;
    }

public:
    Trie() : raiz(make_unique<Nodo>()) {}

    void insertar(const string& palabra) {
        Nodo* nodo = raiz.get();
        for (char c : palabra) {
            auto& hijo = nodo->hijos[c];
            if (!hijo) hijo = make_unique<Nodo>();
            nodo = hijo.get();
        }
        nodo->esFin = true;
    }

    bool buscar(const string& palabra) const {
        const Nodo* nodo = recorrer(palabra);
        return nodo != nullptr && nodo->esFin;
    }

    bool empiezaCon(const string& prefijo) const {
        return recorrer(prefijo) != nullptr;
    }

    bool eliminar(const string& palabra) {
        if (!buscar(palabra)) return false;
        eliminarRec(raiz.get(), palabra, 0);
        return true;
    }

    void recorridoDFS() {
        dfs(raiz.get());
    }

    void imprimirContadores() const {
        string actual;
        mostrarContadores(raiz.get(), actual);
    }
};

int main() {
    Trie trie;
    for (const char* p : {"casa", "casco", "caso", "perro", "pera"})
        trie.insertar(p);

    trie.recorridoDFS();
    trie.recorridoDFS();
    trie.recorridoDFS();

    trie.imprimirContadores();

    return 0;
}