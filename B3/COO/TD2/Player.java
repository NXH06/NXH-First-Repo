public class Player {
    int STARTING_LIVES = 1;
    int RESISTANCE = 1;
    int nbLives;
    int resistance;
    int nbPoints;

    public static final Player MARIO = new Player();
    private Player() {
        nbPoints = 0;
        nbLives = STARTING_LIVES;
    }
    public int getNbLives() {
        return nbLives;
    }
    public void changeNbLives(int n) {
        this.nbLives += n;
    }
    public int getResistance() {
        return resistance;
    }
}
