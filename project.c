Nimport sys

def get_user_choice(options, prompt):
    print(prompt)
    for i, option in enumerate(options, 1):
        print(f"{i}. {option}")

    while True:
        try:
            choice = int(input("Enter the number of your choice: "))
            if 1 <= choice <= len(options):
                return options[choice - 1]
            else:
                print("Invalid choice. Please select a valid number.")
        except ValueError:
            print("Please enter a number.")

def analyze_symptoms(symptoms):
    symptom_to_disease = {
        "Yellow Spots": "Mosaic Virus",
        "Brown Spots": "Rust",
        "Wilting": "Blight",
        "White Powder": "Powdery Mildew",
        "Black Spots": "Leaf Spot Disease",
        "Curled Leaves": "Aphid Infestation",
        "Stunted Growth": "Nutrient Deficiency",
        "Holes in Leaves": "Pest Infestation",
        "Rotting Roots": "Root Rot",
        "Cracked Fruits": "Blossom End Rot"
    }

    for symptom in symptoms:
        if symptom in symptom_to_disease:
            return symptom_to_disease[symptom]
    return "Healthy"

def get_treatment(disease):
    treatments = {
        "Blight": "Apply fungicides and remove infected plants.",
        "Rust": "Use sulfur-based fungicides and avoid overhead watering.",
        "Mosaic Virus": "Remove infected plants and control insect vectors.",
        "Powdery Mildew": "Apply neem oil or sulfur-based fungicides.",
        "Leaf Spot Disease": "Use copper-based fungicides and ensure proper air circulation.",
        "Aphid Infestation": "Use insecticidal soap or neem oil to control aphids.",
        "Nutrient Deficiency": "Apply balanced fertilizers and organic compost.",
        "Pest Infestation": "Use natural predators like ladybugs and organic pesticides.",
        "Root Rot": "Improve soil drainage and avoid overwatering.",
        "Blossom End Rot": "Ensure consistent watering and apply calcium supplements.",
        "Healthy": "No treatment needed."
    }
    return treatments.get(disease, "Consult an agricultural expert.")

def get_prevention_tips(disease):
    prevention_tips = {
        "Blight": "Rotate crops, avoid excessive watering, and remove infected plant debris.",
        "Rust": "Ensure good air circulation, use resistant plant varieties, and remove infected leaves.",
        "Mosaic Virus": "Control insect vectors like aphids and use virus-resistant plant varieties.",
        "Powdery Mildew": "Avoid excessive humidity, prune affected areas, and apply organic fungicides.",
        "Leaf Spot Disease": "Use disease-free seeds, avoid overcrowding, and water plants at the base.",
        "Aphid Infestation": "Introduce beneficial insects like ladybugs and remove heavily infested leaves.",
        "Nutrient Deficiency": "Test soil regularly, apply proper fertilizers, and maintain soil health.",
        "Pest Infestation": "Use row covers, handpick pests, and introduce beneficial insects.",
        "Root Rot": "Plant in well-drained soil, avoid excessive watering, and ensure proper aeration.",
        "Blossom End Rot": "Maintain consistent soil moisture and apply calcium-rich amendments.",
        "Healthy": "Maintain good farming practices and regularly inspect crops for early signs of disease."
    }
    return prevention_tips.get(disease, "Follow general best practices for crop health.")

def main():
    print("=== AI-Driven Crop Disease Prediction System ===")

    crops = ["Wheat", "Rice", "Maize", "Tomato", "Potato", "Cotton", "Soybean", "Barley", "Sugarcane", "Peanut"]
    crop_type = get_user_choice(crops, "Select the crop type:")

    symptoms_list = [
        "Yellow Spots", "Brown Spots", "Wilting", "White Powder", "Black Spots", "Curled Leaves",
        "Stunted Growth", "Holes in Leaves", "Rotting Roots", "Cracked Fruits"
    ]
    print("Select observed symptoms (Enter multiple numbers separated by commas):")
    for i, symptom in enumerate(symptoms_list, 1):
        print(f"{i}. {symptom}")

    while True:
        try:
            selected_symptom_numbers = input("Enter symptom numbers: ").split(',')
            selected_symptoms = [symptoms_list[int(num) - 1] for num in selected_symptom_numbers if num.strip().isdigit() and 1 <= int(num) <= len(symptoms_list)]
            if selected_symptoms:
                break
            else:
                print("Invalid input. Please enter valid numbers.")
        except ValueError:
            print("Invalid input. Please enter numbers only.")

    weather_conditions = ["Hot and Dry", "Humid and Wet", "Cold and Frosty", "Moderate Climate"]
    weather = get_user_choice(weather_conditions, "Select the current weather conditions:")

    disease = analyze_symptoms(selected_symptoms)
    treatment = get_treatment(disease)
    prevention = get_prevention_tips(disease)

    print("\n===== Diagnosis Result =====")
    print(f"Selected Crop: {crop_type}")
    print(f"Observed Symptoms: {', '.join(selected_symptoms)}")
    print(f"Current Weather: {weather}")
    print(f"Predicted Disease: {disease}")
    print(f"Suggested Treatment: {treatment}")
    print("Prevention Tips:")
    print(prevention)

if _name_ == "_main_":
    main()