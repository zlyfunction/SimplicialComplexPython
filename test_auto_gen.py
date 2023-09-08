from SimplicialComplex import *
import random

mesh_name = 'circle.obj'
output_file_name = 'test_code.cpp'
mesh = load_obj(mesh_name)
n_samples = 5
v_samples = random.sample(list(mesh.vertices), n_samples)

with open(output_file_name, 'w') as file:
    # print(v_samples)
    for v in v_samples:
        file.write("t = m.tuple_from_id(PV, {});\n".format(v[0]))
        file.write("sc_v = get_sorted_sc(m, SimplicialComplex::open_star(m, Simplex(PV, t)).get_simplex_vector());\n")
        o_star = mesh.open_star(v)
        o_star = sorted(o_star, key=lambda x: (len(x),x))
        file.write("REQUIRE(sc_v.size() == {});\n".format(len(o_star)))
        for simplex in o_star:
            for i in range(len(simplex)):
                file.write("CHECK(sc_v[{}][{}] == {});\n".format(o_star.index(simplex), i, simplex[i]))
        file.write("\n")
    
