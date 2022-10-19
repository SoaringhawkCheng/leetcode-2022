import java.util.HashMap;
import java.util.concurrent.ConcurrentHashMap;

public class BlockChain {

    private BlockNode root;
    private ConcurrentHashMap<String, BlockNode> nodeMap;
    private int capacity = 6;
    private boolean state; //

    public BlockChain(BlockNode root) {
        this.root = root; // index = 1
        this.nodeMap = new ConcurrentHashMap<>();
        this.nodeMap.put(root.hash, root);
    }

    public boolean joinChain(BlockNode node) {
        BlockNode father = getFatherNode(node);
        if (father.index == capacity - 1) {
            synchronized () {
                state = !state;
            }

        }
    }

    public void putData(String hash) {

    }

    private BlockNode getFatherNode(BlockNode node) {
        // TODO: 基于某种随机算法或业务规则，不知道如何实现，返回root示意
        return root;
    }

    public static class BlockNode {
        protected String hash;
        protected String prevHash;
        protected int index;
        protected HashMap<String, String> payload;
    }

    public static class BlockCache {
        protected HashMap<String, String> cache;
    }
}
