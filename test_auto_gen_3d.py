from SimplicialComplex import *
import random

# Load mesh
path = 'data/'
mesh_name = 'bunny_tetwild_80.msh'  # change to msh
output_file_name = 'test_code_3d.cpp'
test_function_name = 'top_coface_simplex' # 'open_star', 'closed_star', 'link'
mesh = load_msh(path+mesh_name)

# Choose test function
if test_function_name == 'open_star':
    test_function = mesh.open_star
elif test_function_name == 'closed_star':
    test_function = mesh.closed_star
elif test_function_name == 'link':
    test_function = mesh.link
elif test_function_name == 'simplex_with_boundary':
    test_function = mesh.boundary
elif test_function_name == 'top_coface_simplex':
    test_function = mesh.top_coface_simplex
else:
    raise Exception("Function name not recognized")

# Sample some simplices
n_samples = 5
v_samples = random.sample(list(mesh.vertices), n_samples)
e_samples = random.sample(list(mesh.edges), n_samples)
f_samples = random.sample(list(mesh.faces), n_samples)
t_samples = random.sample(list(mesh.tetrahedra), n_samples)

# Write test code
with open(output_file_name, 'w') as file:

    cpp_code = 'TEST_CASE("{test_func}_{mesh_name}", "[simplicial_complex][{test_func}][3D]")\n'.format(mesh_name=mesh_name.split(".")[0], test_func = test_function_name)+\
    '{\n'+\
    '    Eigen::MatrixXd V;\n'+\
    '    Eigen::MatrixXi T;\n'+\
    '    Eigen::MatrixXi F;\n'+\
    '    Eigen::VectorXi Tritag, Tettag;\n'+\
    '    std::string name = "/{mesh_file}";\n'.format(mesh_file = mesh_name)+\
    '    std::string path;\n'+\
    '    path.append(WMTK_DATA_DIR);\n'+\
    '    path.append(name);\n'+\
    '    igl::readMSH(path, V, F, T, Tritag, Tettag);\n'+\
    '    tests_3d::DEBUG_TetMesh m;\n'+\
    '    RowVectors4l Tr;\n'+\
    '    Tr.resize(T.rows(), T.cols());\n'+\
    '    assert(T.cols() == 4);\n'+\
    '    for (long i = 0; i < T.rows(); i++) {\n'+\
    '        Tr(i, 0) = T(i, 0);\n'+\
    '        Tr(i, 1) = T(i, 1);\n'+\
    '        Tr(i, 2) = T(i, 2);\n'+\
    '        Tr(i, 3) = T(i, 3);\n'+\
    '    }\n'+\
    '    m.initialize(Tr);\n'+\
    '    \n'+\
    '    Tuple t;\n'+\
    '    std::vector<std::vector<long>> sc_v, sc_e, sc_f, sc_t;\n'
    
    file.write(cpp_code)

    # print(v_samples)
    for v in v_samples:
        file.write("    t = m.tuple_from_id(PV, {});\n".format(v[0]))
        file.write("    REQUIRE(m.is_valid_slow(t));")
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
        file.write("    REQUIRE(m.is_valid_slow(t));")
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
        file.write("    REQUIRE(m.is_valid_slow(t));")
        file.write("    sc_f = get_sorted_sc(m, SimplicialComplex::{test_func}(m, Simplex(PF, t)).get_simplex_vector());\n".format(test_func = test_function_name))
        sc = test_function(f)
        sc = sorted(sc, key=lambda x: (len(x),x))
        file.write("    REQUIRE(sc_f.size() == {});\n".format(len(sc)))
        for simplex in sc:
            for i in range(len(simplex)):
                file.write("    CHECK(sc_f[{}][{}] == {});\n".format(sc.index(simplex), i, simplex[i]))
        file.write("\n")

    # print(t_samples)
    for tet in t_samples:
        file.write("    t = m.tet_tuple_from_vids({}, {}, {}, {});\n".format(tet[0], tet[1], tet[2], tet[3]))
        file.write("    REQUIRE(m.is_valid_slow(t));")
        file.write("    sc_t = get_sorted_sc(m, SimplicialComplex::{test_func}(m, Simplex(PT, t)).get_simplex_vector());\n".format(test_func = test_function_name))
        sc = test_function(tet)
        sc = sorted(sc, key=lambda x: (len(x),x))
        file.write("    REQUIRE(sc_t.size() == {});\n".format(len(sc)))
        for simplex in sc:
            for i in range(len(simplex)):
                file.write("    CHECK(sc_t[{}][{}] == {});\n".format(sc.index(simplex), i, simplex[i]))
        file.write("\n")
    
    file.write("}\n")
