#version 330
in vec4 vColor;
in vec3 normal;
in vec3 posFrag;
in vec2 uvFrag;

struct BaseLight{
    vec3 color;
    float ambientInten;
    float diffuseInten;
};

struct DirectionalLight{
    BaseLight base;
    vec3 lightDir;
};

struct PointLight{
    BaseLight base;
    vec3 pos;
    float constant;
    float lineal;
    float exponential;
};

uniform DirectionalLight directionalLight;
uniform PointLight pointLight;
uniform vec3 cameraPos;
uniform float specularInten;
uniform float shininess;
uniform float time;

out vec4 colour;

vec3 CalculateLightValues(BaseLight base, vec3 norm, vec3 lDir, vec3 viewDir) {
    //Ambient
    vec3 ambient = base.ambientInten * base.color;
    //Diffuse
    float diff = max(dot(normalize(norm), normalize(directionalLight.lightDir)), 0.0f);
    vec3 diffuse = base.diffuseInten * base.color * diff;
    //Specular
    vec3 viewDir = normalize(cameraPos - posFrag);
    vec3 halfWayVec = normalize(directionalLight.lightDir + viewDir);
    float spec = pow(max(dot(normalize(norm), halfWayVec), 0.0f), shininess);
    vec3 specular = base.color * specularInten * spec;
    return ambient + diffuse + specular;
}

vec3 CalculateDirecionalLight(BaseLight base) {
    vec3 norm = normalize(normal);
    vec3 lDir  = normalize(posFrag - pointLight.pos);
    vec3 viewDir = normalize(cameraPos - posFrag);

    //Ambient
    vec3 ambient = base.ambientInten * base.color;
    //Diffuse
    float diff = max(dot(norm, lDir), 0.0f);
    vec3 diffuse = base.diffuseInten * base.color * diff;
    //Specular
    vec3 halfWayVec = normalize(lDir + viewDir);
    float spec = pow(max(dot(norm, halfWayVec), 0.0f), shininess);
    vec3 specular = base.color * specularInten * spec;

    float d = distance(posFrag, pointLight.pos);
    float attenuation = 1/(pointLight.exponential * d * d + pointLight.lineal * d + pointLight.constant);

    return (ambient + diffuse + specular) * attenuation;
}

void main(){
    

    vec3 luzFinal = vec3(0,0,0);
    luzFinal = CalculateDirecionalLight(directionalLight.base);

    float vel = 0.9*10 + 0.1*(cos(time + posFrag.x * 100) + 1)/2;
    float val1 = (clamp((cos(time * vel + posFrag.y*10)+1)/2, 0.9, 1) + 0.1);
    float val2 = (clamp((cos(time * vel*3 + posFrag.y*100)+1)/2, 0.9, 1) + 0.1);
    colour = vec4(uvFrag.x, uvFrag.y, 0, 1 )*val1*val2 * vec4(luzFinal, 1.0); 
}