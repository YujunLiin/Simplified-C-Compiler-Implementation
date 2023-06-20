#include "type.h"

Type::Type(ValueType valueType) {
    this->type = valueType;
}

string Type::getTypeInfo() {
    switch(this->type) {
        case VALUE_BOOL:
            return "bool";
        case VALUE_INT:
            return "int";
        case VALUE_CHAR:
            return "char";
        case VALUE_VOID:
            return "void";
        case VALUE_STRING:
            return "string";
        case COMPOSE_STRUCT:
            return "struct";
        case COMPOSE_ARRAY:
            return "array";
        case COMPOSE_UNION:
            return "union";
        case COMPOSE_FUNCTION:
            return "function";
        default:
            cerr << "shouldn't reach here, typeinfo";
            assert(0);
    }
    return "?";
}