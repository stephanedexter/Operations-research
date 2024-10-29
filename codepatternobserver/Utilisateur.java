package Observer;
public class Utilisateur
{

  public static void main(String[] args)
  {
    Vehicule vehicule = new Vehicule();
    vehicule.setDescription("Véhicule bon marché");
    vehicule.setPrix(5000.0);
    VueVehicule vueVehicule = new VueVehicule(vehicule,1);
    vueVehicule.redessine();
    vehicule.setPrix(4500.0);
    VueVehicule vueVehicule2 = new VueVehicule(vehicule,2);
    vehicule.setPrix(5500.0);
  }
}
