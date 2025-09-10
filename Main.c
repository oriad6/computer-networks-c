#include "build_net.h"
#include "prim.h"
#include "paths.h"
#include "path_finding.h"
#include "free.h"

int main()
{
    int n;
    EdgeList* Net;
    int* Prim;
    EdgeList* PrimPath;
    int first, last;

    scanf("%d", &n);
    Net = build_net(n);
    Prim = build_prim_tree(Net, n);
    PrimPath = build_paths(Prim, n);

    scanf("%d%d", &first, &last);

    find_and_print_path(PrimPath, n, first, last);

    freeAll(Net, PrimPath, Prim, n);

    return 0;
}
