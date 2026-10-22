import java.util.ArrayList;

public class Main {
    public void getDoubleLives() {
        System.out.println(Player.MARIO.getNbLives());
        LifeBonusBlock lbb = new LifeBonusBlock();
        DoubleEffectBlock deb = new DoubleEffectBlock(lbb);
        deb.applyEffect();
        System.out.println(Player.MARIO.getNbLives());
    }
    public void createGraphicalBlockList() {
        /* Créer les classes GraphicalBlock indépendamment;
        Séparer l'affichage de la logique, c'est-à-dire le bas niveau du haut niveau */
        ArrayList<Block> blocks = new ArrayList<>();
        blocks.add(new JackpotBlock());
        blocks.add(new LifeBonusBlock());
        ArrayList<GraphicalBlock> lg = new ArrayList<>();

        for (Block block: blocks) {
            lg.add(block.getGraphicalBlock());
        }
    }
}
