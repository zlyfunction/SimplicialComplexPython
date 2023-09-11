from SimplicialComplex import *
import random

# Load mesh
path = 'data/'
mesh_name = 'circle.obj'
output_file_name = 'test_code.cpp'
test_function_name = 'simplex_with_boundary' # 'open_star', 'closed_star', 'link'
mesh = load_obj(path+mesh_name)

# Choose test function
if test_function_name == 'open_star':
    test_function = mesh.open_star
elif test_function_name == 'closed_star':
    test_function = mesh.closed_star
elif test_function_name == 'link':
    test_function = mesh.link
elif test_function_name == "simplex_with_boundary":
    test_function = mesh.boundary
else:
    raise Exception("Function name not recognized")

# Sample some simplices
n_samples = 5
v_samples = random.sample(list(mesh.vertices), n_samples)
e_samples = random.sample(list(mesh.edges), n_samples)
f_samples = random.sample(list(mesh.faces), n_samples)

# Write test code
with open(output_file_name, 'w') as file:

    cpp_code = 'TEST_CASE("{test_func}_{mesh_name}", "[simplicial_complex][{test_func}][2D]")\n'.format(mesh_name=mesh_name.split(".")[0], test_func = test_function_name)+\
    '{\n'+\
    '    RowVectors3d V;\n'+\
    '    RowVectors3l F;\n'+\
    '    std::string name = "/{mesh_file}";\n'.format(mesh_file = mesh_name)+\
    '    std::string path;\n'+\
    '    path.append(WMTK_DATA_DIR);\n'+\
    '    path.append(name);\n'+\
    '    igl::read_triangle_mesh(path, V, F);\n'+\
    '    tests::DEBUG_TriMesh m;\n'+\
    '    m.initialize(F);\n'+\
    '\n'+\
    '    Tuple t;\n'+\
    '    std::vector<std::vector<long>> sc_v, sc_e, sc_f;\n'
    
    file.write(cpp_code)

    # print(v_samples)
    for v in v_samples:
        file.write("    t = m.tuple_from_id(PV, {});\n".format(v[0]))
        file.write("    sc_v = get_sorted_sc(m, SimplicialComplex::{test_func}(m, Simplex(PV, t)).get_simplex_vector());\n".format(test_func = test_function_name))
        sc = test_function(v)
        sc = sorted(sc, key=lambda x: (len(x),x))
        file.write("    REQUIRE(sc_v.size() == {});\n".format(len(sc)))
        for simplex in sc:
            for i in range(len(simplex)):
                file.write("    CHECK(sc_v[{}][{}] == {});\n".format(sc.index(simplex), i, simplex[i]))
        file.write("\n")
    
    # print(e_samples)
    for e in e_samples:
        file.write("    t = m.edge_tuple_from_vids({},{});\n".format(e[0], e[1]))
        file.write("    sc_e = get_sorted_sc(m, SimplicialComplex::{test_func}(m, Simplex(PE, t)).get_simplex_vector());\n".format(test_func = test_function_name))
        sc = test_function(e)
        sc = sorted(sc, key=lambda x: (len(x),x))
        file.write("    REQUIRE(sc_e.size() == {});\n".format(len(sc)))
        for simplex in sc:
            for i in range(len(simplex)):
                file.write("    CHECK(sc_e[{}][{}] == {});\n".format(sc.index(simplex), i, simplex[i]))
        file.write("\n")

    # print(f_samples)
    for f in f_samples:
        file.write("    t = m.face_tuple_from_vids({}, {}, {});\n".format(f[0], f[1], f[2]))
        file.write("    sc_f = get_sorted_sc(m, SimplicialComplex::{test_func}(m, Simplex(PF, t)).get_simplex_vector());\n".format(test_func = test_function_name))
        sc = test_function(f)
        sc = sorted(sc, key=lambda x: (len(x),x))
        file.write("    REQUIRE(sc_f.size() == {});\n".format(len(sc)))
        for simplex in sc:
            for i in range(len(simplex)):
                file.write("    CHECK(sc_f[{}][{}] == {});\n".format(sc.index(simplex), i, simplex[i]))
        file.write("\n")
    
    file.write("}\n")
