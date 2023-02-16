bool Tree::Has(const std::vector<std::string>& node) const {
  const Node* current_node = &root;
  for (size_t i = 0; i < node.size(); ++i) {
    if (current_node->children.find(node[i]) == current_node->children.end()) {
      return false;
    }

    current_node = &current_node->children.at(node[i]);
  }

  return true;
}

void Tree::Insert(const std::vector<std::string>& node) {
  Node* current_node = &root;
  for (size_t i = 0; i < node.size(); ++i) {
    current_node = &current_node->children[node[i]];
  }
}

void Tree::Delete(const std::vector<std::string>& node) {
  Node* current_node = &root;
  for (size_t i = 0; i < node.size(); ++i) {
    if (current_node->children.find(node[i]) == current_node->children.end()) {
      return;
    }

    if (i == node.size() - 1) {
      current_node->children.erase(node[i]);
    } else {
      current_node = &current_node->children.at(node[i]);
    }
  }
}