import java.util.ArrayList;

public class PetStore {
	private ArrayList<Pet> pets = new ArrayList<Pet>();

	public void sounds() {
		for (Pet pet : pets) {
			System.out.println(pet.petSound);

		}	
		System.out.println() ;
	}

	public void treats() {
		for (Pet pet : pets) {
			if (pet.petType == PetType.CAT)
				System.out.println("Give " + pet.petName + " some catnip");
			else if (pet.petType == PetType.DOG)
				System.out.println("Give " + pet.petName + " a bone");	
			else 
				System.out.println("Give" + pet.petName + " a treat");
		}
		System.out.println();
	}

	public void fun() {
		for (Pet pet : pets) {
			if (pet.petType == PetType.CAT)
				System.out.println("Watch " + pet.petName + " sleep");
			else if (pet.petType == PetType.DOG)
				System.out.println("Throw a frisbee to " + pet.petName);	
			else 
				System.out.println("Play with " + pet.petName);
		}	
		System.out.println() ;
	}

	public void addPet( Pet pet ) {
		pets.add( pet ) ;
	}

	public void listPets() {
		for( Pet pet : pets ) {
			System.out.println(pet);
		}
	}

	public static void main(String[] args) {
		PetStore myStore = new PetStore() ;

		myStore.addPet(new Pet("Buttons", PetType.CAT,"Meow"));
		myStore.addPet(new Pet("Boxer", PetType.DOG, "Woof" ));
		myStore.addPet(new Pet("Dax", PetType.CAT ,"Meow"));

		myStore.fun();
		myStore.treats();
		myStore.sounds();

	}

}
