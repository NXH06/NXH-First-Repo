public class DoubleEffectBlock extends Block {
    protected Block block; // le bloc dont l'effet D.E.B. va dédoubler
    public DoubleEffectBlock(Block block) {
        super();
        this.block = block;
    }
    protected void applyEffect() {
        this.block.applyEffect();
        this.block.applyEffect();
    }
    public int getNbCoins() {
        return 2 * this.block.getNbCoins();
    }
}