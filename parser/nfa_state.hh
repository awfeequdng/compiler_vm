#pragma once
#include <set>
#include <memory>

namespace CompilerVm
{
    enum class NfaNode {
        NODE_NONE,
        NODE_START,
        NODE_END,
        NODE_BOTH
    };

    enum class NfaEdge {
        EDGE_EPSION,    // 出边为ε
        EDGE_CCL,       // 出边为字符集
        EDGE_EMPTY      // 没有出边
    };
    
    class NfaState {
    public:
        NfaEdge edgeType() {
            return _edgeType;
        }
        void setEdgeType(NfaEdge type) {
            _edgeType = type;
        }

        void setNodeIndex(int idx) {
            _nodeIndex = idx;
        }

        void reset() {
            _edgeType = NfaEdge::EDGE_EMPTY;
            _nodeType = NfaNode::NODE_NONE;
            _charCollect.clear();
            _nextState1.reset();
            _nextState2.reset();
            _nodeIndex = -1;
        }
    private:
        NfaEdge _edgeType;                        // 出边类型 
        NfaNode _nodeType;                        // NFA节点类型
        std::set<char> _charCollect;              // 字符集
        std::shared_ptr<NfaState> _nextState1;    // nfa的第一个下一跳状态，最多两个下一跳
        std::shared_ptr<NfaState> _nextState2;    // nfa的第二个下一跳，可以为空，只有含有两个ε时这条边才有效

        int _nodeIndex;                           // 节点索引
    };
} // namespace CompilerVm
