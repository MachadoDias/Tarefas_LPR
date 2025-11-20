import sqlalchemy as sa
from sqlalchemy.orm import Mapped, mapped_column, sessionmaker, declarative_base, relationship

db = sa.create_engine('postgresql+psycopg2://machado:181007@localhost/database')
Session = sessionmaker(bind=db)
Base = declarative_base()

class Aluno(Base):
    __tablename__ = "alunos"
    id: Mapped[int] = mapped_column(primary_key=True)
    nome: Mapped[str]
    email: Mapped[str]
    dataCadastro: Mapped[str]
    matriculas: Mapped[list["Matricula"]] = relationship("Matricula", back_populates="aluno")
class Matricula(Base):
    __tablename__ = "matriculas"
    id: Mapped[int] = mapped_column(primary_key=True)

    aluno_id: Mapped[int] = mapped_column(sa.ForeignKey("alunos.id"))
    aluno: Mapped["Aluno"] = relationship("Aluno", back_populates="matriculas", uselist=False)

    curso_id: Mapped[int] = mapped_column(sa.ForeignKey("cursos.id"))
    curso: Mapped["Curso"] = relationship("Curso", back_populates="matriculas", uselist=False)

    status: Mapped[str]
    progresso: Mapped[str]
class Curso(Base):
    __tablename__ = "cursos"
    id: Mapped[int] = mapped_column(primary_key=True)
    titulo: Mapped[str]
    descricao: Mapped[str]

    instrutor_id: Mapped[int] = mapped_column(sa.ForeignKey("instrutores.id"))
    instrutor: Mapped["Instrutor"] = relationship("Instrutor", back_populates="cursos", uselist=False)

    matriculas: Mapped[list["Matricula"]] = relationship("Matricula", back_populates="curso")
class Instrutor(Base):
    __tablename__ = "instrutores"
    id: Mapped[int] = mapped_column(primary_key=True)
    nome: Mapped[str]
    email: Mapped[str]
    cursos: Mapped[list["Curso"]] = relationship("Curso", back_populates="instrutor")

    perfil: Mapped["PerfilInstrutor"] = relationship("PerfilInstrutor", back_populates="instrutor", uselist=False)
class PerfilInstrutor(Base):
    __tablename__ = "perfis_instrutores"
    id: Mapped[int] = mapped_column(primary_key=True)
    biografia: Mapped[str]
    portifolio: Mapped[str]
    instrutor_id: Mapped[int] = mapped_column(sa.ForeignKey("instrutores.id"), unique=True)
    instrutor: Mapped["Instrutor"] = relationship("Instrutor", back_populates="perfil")

def Main() -> None:
    Base.metadata.create_all(db)
    session = Session()
    instrutor = Instrutor(
        nome="Carlos Silva",
        email="carlos@exemplo.com",
        perfil=PerfilInstrutor(
            biografia="Instrutor de Python",
            portifolio="https://portfolio.com/carlos"
        )
    )

    curso = Curso(
        titulo="Python para Iniciantes",
        descricao="Curso básico",
        instrutor=instrutor
    )

    aluno = Aluno(
        nome="João",
        email="joao@exemplo.com",
        dataCadastro="2025-11-20"
    )

    matricula = Matricula(
        aluno=aluno,
        curso=curso,
        status="ativo",
        progresso="0%"
    )

    session.add_all([instrutor, curso, aluno, matricula])

    session.commit()

    alunos = session.query(Aluno).all()
    for a in alunos:
        print(a.id, a.nome)

    session.close()

if __name__ == "__main__":
    Main()
