package Observer;

public class VueVehicule implements Observateur
{
  protected Vehicule vehicule;
  protected String texte = "";
  protected int id;

  public VueVehicule(Vehicule vehicule, int id)
  {
    this.id = id;
    this.vehicule = vehicule;
    vehicule.ajoute(this);
    metAJourTexte();
  }

  protected void metAJourTexte()
  {
    texte = id + " : Description " + vehicule.description + 
      " Prix : " + vehicule.prix;
  }

  public void actualise()
  {
    metAJourTexte();
    this.redessine();
  }

  public void redessine()
  {
    System.out.println(texte);
  }
}
