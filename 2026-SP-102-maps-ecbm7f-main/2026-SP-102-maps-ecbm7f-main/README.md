# Implementation of Maps

In this project, you'll be creating two implementations of a _Map (abstract interface)_, an AVL tree and a HashMap.

There is no analysis portion to this project, but unit tests will confirm if your implementations are being properly maintained for efficiency (in terms height and load factor).

---
## GAI Usage Policy

* You **MAY** utilize GAI tools to assist you with developing and debugging your code for this project.
    * You may use any GAI tools you wish, as long as you document them completely.
* You **MUST** document your GAI usage and submit it to Canvas.
    * Copy-paste or export the **entire** prompt-response session(s) and save this information in a document which will be submitted to Canvas
    * If you choose not to utilize GAI at all, then simply state that in your document.

---
## Implementation: AVL Tree and HashMap

This section of the project is **automatically graded** and submitted to **![git-classes](https://cs-mst-docs.git-pages.mst.edu/workflow-docs/student/git/)**

Complete the following for the _Implementation_ portion:
1. Edit `src/map_implementations/avl.ipp` to build the `AVL` class.
    * You may reference the `bst.ipp` for an example that is **not** self-balancing.
    * Your implementation must be self-balancing (maintain a logarithmic relationship between the height of the tree and the number of records).
    * In addition to the standard _Map_ interface, you must implement the methods **get_upper_bound** and **get_lower_bound** from the _SortedMap_ interface.
    * Verify your code using the tests labeled `unit_avl` and `memory_avl` as you go.
2. Edit `src/map_implementations/hashmap.ipp` to build the `HashMap` class and its iterator
    * This implementation must use closed addressing with linked-list buckets as its collision management policy and it must maintain a load factor **below 0.7**.
    * Verify your code using the tests labeled `unit_hm` and `memory_hm` as you go.
3. Complete the `static_analysis` and `format` tests, and submit your code before the deadline.

---

